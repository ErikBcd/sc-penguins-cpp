#include "client.h"

namespace Client {
    Game_Client::Game_Client(Logic::Logic &logic) {
        this->used_logic = &logic;
    }

    std::string Game_Client::trim_message(std::string &msg) {
        std::string trimmed;
        if (msg.find_first_of("<protocol>", 0) == 0) {
            trimmed = msg.substr(10, msg.length()-1);
        }
        if (trimmed.find_first_of("<joined roomId", 0) == 0) {
            size_t end = trimmed.find_first_of(">", 0);
            trimmed = trimmed.substr(end, trimmed.length()-1-end);
        }

        size_t end = msg.find("</protocol>");
        if (end != std::string::npos) {
            trimmed = trimmed.substr(0, trimmed.length() - 12);
        }

        return trimmed;
    }

    void Game_Client::handle_message(const MessageHandling::SC_Message &message) {
        MessageHandling::SC_Message answer;

        switch (message.get_type())
        {
        case MessageHandling::Message_Type::MEMENTO:
            gameState = msg_handler.get_GameState_from_message(message.get_content());
            gameState.current_team = team;
            return;
        case MessageHandling::Message_Type::MOVE_REQUEST: {
            Game::Move move = used_logic->get_move(gameState);
            tcp_client.send(msg_handler.create_move_message(move, room_id));
            return;
            }
        case MessageHandling::Message_Type::RESULT:
            result = msg_handler.get_result(message);
            game_ended = true;
            return;
        case MessageHandling::Message_Type::WELCOME_MESSAGE:
            msg_handler.get_welcome_data(message.get_content(), room_id, team);
            gameState.current_team = team;
            return;
        default:
            game_ended = true;
            break;
        }

        return;
    }

    void Game_Client::game_loop() {
        while (!game_ended) {
            std::string msg = tcp_client.receive();
            MessageHandling::SC_Message message = msg_handler.create_message(msg);
            handle_message(message);
            if (message.get_type() == MessageHandling::Message_Type::RESULT || message.get_type() == MessageHandling::Message_Type::UNKNOWN) {
                std::cout << "#########+- RESULT -+#########\n" 
                          << message.get_content() << std::endl
                          << "##############################\n";
            }
        }
    }

    void Game_Client::Start(std::string ip, unsigned short port) {
        // #1 Connect to server
        tcp_client.connect(ip, port);
        tcp_client.send(msg_handler.create_join_request());
        
        // #2 Gather game info
        std::string info = tcp_client.receive();

        handle_message(MessageHandling::SC_Message(trim_message(info), 
                MessageHandling::Message_Type::WELCOME_MESSAGE));

        game_loop();

        // #4 Print ending information
        std::cout << result.to_string() << std::endl;
    }
}