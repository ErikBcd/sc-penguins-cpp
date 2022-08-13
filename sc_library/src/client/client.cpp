#include "client.h"

namespace Client {
    Game_Client::Game_Client(Logic::Logic &logic) {
        this->used_logic = &logic;
    }

    std::string Game_Client::trimMessage(std::string &msg) {
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

    void Game_Client::handleMessage(const MessageHandling::SC_Message &message) {
        MessageHandling::SC_Message answer;

        switch (message.getType())
        {
        case MessageHandling::Message_Type::MEMENTO:
            gameState = msg_handler.getGameStateFromMessage(message.getContent());
            gameState.currentTeam = team;
            return;
        case MessageHandling::Message_Type::MOVE_REQUEST: {
            Game::Move move = used_logic->getMove(gameState);
            tcp_client.send(msg_handler.createMoveMessage(move, room_id));
            return;
            }
        case MessageHandling::Message_Type::RESULT:
            result = msg_handler.getResult(message);
            game_ended = true;
            return;
        case MessageHandling::Message_Type::WELCOME_MESSAGE:
            msg_handler.getWelcomeData(message.getContent(), room_id, team);
            gameState.currentTeam = team;
            return;
        default:
            game_ended = true;
            break;
        }

        return;
    }

    void Game_Client::GameLoop() {
        while (!game_ended) {
            std::string msg = tcp_client.receive();
            MessageHandling::SC_Message message = msg_handler.createMessage(msg);
            handleMessage(message);
            if (message.getType() == MessageHandling::Message_Type::RESULT || message.getType() == MessageHandling::Message_Type::UNKNOWN) {
                std::cout << "#########+- RESULT -+#########\n" 
                          << message.getContent() << std::endl
                          << "##############################\n";
            }
        }
    }

    void Game_Client::Start(int argc, char *argv[]) {
        // #1 Connect to server
        if (argc == 3) {
            std::string ip(argv[1]);
            unsigned short port = (unsigned short ) atoi(argv[2]);
            tcp_client.connect(ip, port);
        } else {
            tcp_client.connect();
        }

        tcp_client.send(msg_handler.createJoinRequest());
        // #2 Gather game info
        std::string info = tcp_client.receive();

        handleMessage(MessageHandling::SC_Message(trimMessage(info), 
                MessageHandling::Message_Type::WELCOME_MESSAGE));

        GameLoop();

        // #4 Print ending information
        std::cout << result.toString() << std::endl;
    }
}