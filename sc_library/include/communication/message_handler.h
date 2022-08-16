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
            
            Message_Type get_type_from_tag(const std::string &tagname);

            SC_Message create_message(const std::string &message);

            std::vector<SC_Message> split_message(const std::string &message);

            std::string create_join_request();

            std::string create_move_message(const Game::Move &move, const std::string &roomID);

            void get_welcome_data(const std::string &message, std::string &room_ID, bool &team);

            Game::GameState get_GameState_from_message(const std::string &message);

            Game::GameResult get_result(const SC_Message &msg);
    };
}