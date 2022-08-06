#include "client.h"

namespace Client {
    Game_Client::Game_Client(Logic::Logic logic) {
        this->used_logic = logic;
    }

    void Game_Client::GameLoop() {
        // #1 Wait for move request OR end of game
        while (true) {
            // 1.1 Receive game data
            //     If game has ended, return

            // 1.2 Update gamestate
            
            // 1.3 Get new move from logic
            Game::Move move = used_logic.getMove(gameState);

            // 1.4 Send new move
        }
    }

    void Game_Client::Start(int argc, char *argv[]) {
        // #1 Connect to server
        tcp_client.connect(); //TODO: Add option to change IP and port via console args

        // #2 Gather game info
        std::string info = tcp_client.receive();
        
        // #3 Go into gameloop
        GameLoop();

        // #4 Print ending information
    }
}