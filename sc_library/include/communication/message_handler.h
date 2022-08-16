#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "gameState.h"
#include "move.h"
#include "result.h"
#include "xml_string_writer.h"
#include "pugixml.hpp"

namespace MessageHandling {
    enum class Message_Type {
        RESULT,
        MOVE_REQUEST,
        MOVE,
        WELCOME_MESSAGE,
        MEMENTO,
        UNKNOWN
    };

    class SC_Message
    {
    private:
        Message_Type type;
        std::string content;
    public:
        SC_Message(const std::string &msg_content, const Message_Type &msg_type);
        SC_Message();

        Message_Type get_type() const;
        std::string get_content() const;
        std::string type_as_string() const;
    };
    
    class MessageHandler {
        public:
            MessageHandler();
            
            /**
             * @brief Get the MessageType from a tag-name
             * 
             * @param tagname The value of a xml-type-attribute
             * @return Message_Type The corresponding message type
             */
            Message_Type get_type_from_tag(const std::string &tagname);

            /**
             * @brief Creates a SC_Message from a xml message.
             * 
             * @param message Data of a xml message from the game server.
             * @return SC_Message Message containing the tag and data from the server-message.
             */
            SC_Message create_message(const std::string &message);

            /**
             * @brief Creates a join request for the server
             * 
             * @return String with the join request message
             */
            std::string create_join_request();

            /**
             * @brief Creates a move message.
             * 
             * @param move Move that will be sent
             * @param roomID The roomID of the game.
             * @return std::string Message containing the move.
             */
            std::string create_move_message(const Game::Move &move, const std::string &roomID);

            /**
             * @brief Extracts room_id and team of the client from a welcome message.
             * 
             * @param message Welcome message by the server
             * @param room_ID Pointer to where the room_ID will be stored
             * @param team Pointer to boolean that will store the team
             */
            void get_welcome_data(const std::string &message, std::string &room_ID, bool &team);

            /**
             * @brief Extracts the gamestate data from a message
             * 
             * @param message Memento message
             * @return Game::GameState GameState from message
             */
            Game::GameState get_GameState_from_message(const std::string &message);

            /**
             * @brief Extracts the result data from result message
             * 
             * @param msg Result of the game
             * @return Game::GameResult 
             */
            Game::GameResult get_result(const SC_Message &msg);
    };
}