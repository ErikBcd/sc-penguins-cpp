#pragma once

#include "tcp_connection.h"
#include "message_handler.h"

#include "logic.h"

#include "gameState.h"
#include "result.h"

namespace Client
{
    class Game_Client
    {
        /**
         * @brief GameState of the current game.
         * 
         */
        Game::GameState gameState;

        /**
         * @brief Only true if the game has already ended.
         * 
         */
        bool game_ended = false;

        /**
         * @brief The team this client belongs to.
         *        0 = ONE, 1 = TWO
         * 
         */
        bool team;

        /**
         * @brief The logic that will calculate the moves sent to the server.
         */
        Logic::Logic* used_logic;

        /**
         * @brief Room ID of the current game
         */
        std::string room_id;

        /**
         * @brief Result of the game, only set if game has ended.
         */
        Game::GameResult result;

        /**
         * @brief tcp client for server communication.
         */
        MessageHandling::TCP_Connection tcp_client;

        /**
         * @brief Message handler for parsing xml messages from the server.
         */
        MessageHandling::MessageHandler msg_handler;
    public:
        /**
         * @brief Construct a new Game_Client
         * 
         * @param logic Pointer to the logic that will be used for calculating moves.
         */
        Game_Client(Logic::Logic &logic);

        /**
         * @brief Starts the client.
         * 
         * @param argc Number of command line arguments
         * @param argv Array of command line arguments
         */
        void Start(int argc, char *argv[]);

    private:
        /**
         * @brief Will run until the game has ended. 
         *        Manages the sending of moves and receiving of messages.
         * 
         */
        void game_loop();

        /**
         * @brief Cuts out unnecessary parts of the server messages.
         * 
         * @param msg Raw server message.
         * @return std::string Trimmed server message
         */
        std::string trim_message(std::string &msg);

        /**
         * @brief Handles a server message, depending on the type.
         *        May update gamestate, result or room_id.
         * 
         * @param message Message from the game server.
         */
        void handle_message(const MessageHandling::SC_Message& message);
    };  
} // namespace Client
