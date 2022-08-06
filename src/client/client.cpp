#include "client.h"

namespace Client {
    Game_Client::Game_Client(Logic::Logic logic) {
        this->used_logic = logic;
    }

    std::string Game_Client::GameLoop() {
        // #1 Wait for move request OR end of game
        while (true) {
            // 1.1 Receive game data
            //     If game has ended, return
            std::string msg = tcp_client.receive();

            // 1.1.1 Split memento and moveRequest
            std::vector<MessageHandling::SC_Message> messages = msg_handler.splitMessage(msg);

            // First message is status or result, second is move request
            // If first message is result, quit
            if (messages[0].getType() == MessageHandling::Message_Type::RESULT) {
                return msg_handler.getResult(messages[0]);
            } else {
                gameState = msg_handler.getGameStateFromMessage(messages[0].getContent());
            }
            
            // 1.3 Get new move from logic
            if (messages.size() == 1) {
                return "ERROR: No move request received!\n";
            } else if (messages[1].getType() == MessageHandling::Message_Type::MOVE_REQUEST) {
                Game::Move move = used_logic.getMove(gameState);
                tcp_client.send(msg_handler.createMoveMessage(move, room_id));
            } else {
                return "ERROR: No move request received!\n";
            }

            // TODO: Write actual Message handling
        }
    }

    void Game_Client::Start(int argc, char *argv[]) {
        // #1 Connect to server
        tcp_client.connect(); //TODO: Add option to change IP and port via console args

        // #2 Gather game info
        std::string info = tcp_client.receive();
        
        // #3 Go into gameloop
        std::string result = GameLoop();

        // #4 Print ending information
    }
}