#include "client.h"

namespace Client {
    Game_Client::Game_Client(Logic::Logic &logic) {
        this->used_logic = logic;
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

    MessageHandling::SC_Message Game_Client::handleMessage(const MessageHandling::SC_Message &message) {
        MessageHandling::SC_Message answer;

        switch (message.getType())
        {
        case MessageHandling::Message_Type::MEMENTO:
            gameState = msg_handler.getGameStateFromMessage(message.getContent());
            return MessageHandling::SC_Message("", MessageHandling::Message_Type::UNKNOWN);
        case MessageHandling::Message_Type::MOVE_REQUEST: {
            Game::Move move = used_logic.getMove(gameState);
            answer = MessageHandling::SC_Message(msg_handler.createMoveMessage(move, room_id), MessageHandling::Message_Type::MOVE_REQUEST);
            return answer;
            }
        case MessageHandling::Message_Type::RESULT:
            result = msg_handler.getResult(message);
            break;
        case MessageHandling::Message_Type::WELCOME_MESSAGE:
            msg_handler.getWelcomeData(message.getContent(), room_id, team);
            break;
        default:
            break;
        }

        return MessageHandling::SC_Message("", MessageHandling::Message_Type::UNKNOWN);
    }

    void Game_Client::GameLoop() {
        while (true) {
            // Receive messages
            std::string msg = tcp_client.receive();

            // Handle messages
            std::vector<MessageHandling::SC_Message> messages = msg_handler.splitMessage(msg);
            std::vector<MessageHandling::SC_Message> answers;
            bool gotMoveRequest = false;
            for (MessageHandling::SC_Message message : messages) {
                if (message.getType() == MessageHandling::Message_Type::MOVE_REQUEST) {
                    gotMoveRequest = true;
                }
                answers.push_back(handleMessage(message));
            }

            // Answer the server (or quit)
            if (!gotMoveRequest) {
                return;
            }
            for (MessageHandling::SC_Message answer : answers) {
                if (answer.getType() != MessageHandling::Message_Type::UNKNOWN) {
                    tcp_client.send(answer.getContent());
                }
            }
        }
    }

    void Game_Client::Start(int argc, char *argv[]) {
        // #1 Connect to server
        if (argc == 2) {
            std::string ip(argv[1]);
            unsigned short port = (unsigned short ) atoi(argv[2]);
            tcp_client.connect(ip, port);
        } else {
            tcp_client.connect();
        }
        // #2 Gather game info
        std::string info = tcp_client.receive();

        handleMessage(MessageHandling::SC_Message(trimMessage(info), 
                        MessageHandling::Message_Type::WELCOME_MESSAGE));
        
        // #3 Go into gameloop
        GameLoop();

        // #4 Print ending information
        std::cout << result.toString() << std::endl;
    }
}