#pragma once

#include "../communication/tcp_connection.h"
#include "../communication/message_handler.h"

#include "../logic/logic.h"

#include "../game/gameState.h"
namespace Client
{
    class Game_Client
    {
        Game::GameState gameState;

        /**
         * @brief The team this client belongs to.
         *        0 = ONE, 1 = TWO
         * 
         */
        bool team;

        Logic::Logic used_logic;

        std::string room_id;

        MessageHandler::TCP_Connection tcp_client;
    public:
        Game_Client(Logic::Logic logic);
        ~Game_Client();

        void Start(int argc, char *argv[]);

    private:
        void GameLoop();
    };  
} // namespace Client
