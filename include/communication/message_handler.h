#pragma once

#include <iostream>
#include <string>
#include "../game/gameState.h"
#include "../game/move.h"
#include "pugixml.hpp"

namespace Game_Communication {
    enum class Message_Type {
        RESULT,
        MOVE_REQUEST,
        MOVE,
        WELCOME_MESSAGE,
        MEMENTO,
        UNKNOWN
    };

    class MessageHandler {
        std::string createJoinRequest();

        std::string createMoveMessage(const Game::Move &move, const std::string &roomID);

        std::string getRoomID(const std::string &message);

        Message_Type getMessageType(const std::string &message);

        Game::GameState getGameStateFromMessage(const std::string &message);

        bool getPlayer(const std::string &message);

        bool getWinner(const std::string &message);

        std::string getEndingReason(const std::string &message);
    };
}