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

        Message_Type getType() const;
        std::string getContent() const;
    };
    
    class MessageHandler {
        public:
            MessageHandler();
            
            Message_Type getMessageTypeFromTag(const std::string &tagname);

            std::vector<SC_Message> splitMessage(const std::string &message);

            std::string createJoinRequest();

            std::string createMoveMessage(const Game::Move &move, const std::string &roomID);

            void getWelcomeData(const std::string &message, std::string &room_ID, bool &team);

            Game::GameState getGameStateFromMessage(const std::string &message);

            Game::GameResult getResult(const SC_Message &msg);
    };
}