#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../game/gameState.h"
#include "../game/move.h"
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
            std::vector<SC_Message> splitMessage(std::string message);

            std::string createJoinRequest();

            std::string createMoveMessage(const Game::Move &move, const std::string &roomID);

            std::string getRoomID(const std::string &message);

            Message_Type getMessageType(const std::string &message);

            Game::GameState getGameStateFromMessage(const std::string &message);

            bool getPlayer(const std::string &message);

            bool getWinner(const std::string &message);

            std::string getEndingReason(const std::string &message);

            std::string getResult(const SC_Message &msg);
    };
}