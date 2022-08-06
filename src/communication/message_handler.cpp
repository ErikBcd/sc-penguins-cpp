#include "message_handler.h"

namespace Game_Communication
{
    std::string MessageHandler::createJoinRequest() {
        return "<protocol>\n<join />";
    }

    std::string MessageHandler::createMoveMessage(const Game::Move &move, const std::string &roomID) {
        std::string message(  "<room roomId=\"" + roomID + "\">\n"
                              +"  <data class=\"move\">\n"
                              +"    <from x=\"" + std::to_string(move.start.x) 
                                + "\" y=\"" + std::to_string(move.start.y) + "\"/>"
                              +"    <to x=\"" + std::to_string(move.destination.x) 
                                + "\" y=\"" + std::to_string(move.destination.y) + "\"/>"
                              +"  </data>"
                              +"</room>");

        return message;
    }

    Message_Type MessageHandler::getMessageType(const std::string &message) {
        std::string sub = message.substr(37);
        std::string type("");
        for (size_t i = 0; i < sub.length() && sub[i] != '"'; i++) {
            type += sub[i];
        }

        if (type == "welcomeMessage") { return Message_Type::WELCOME_MESSAGE; }
        if (type == "moveRequest") { return Message_Type::MOVE_REQUEST; }
        if (type == "memento") { return Message_Type::MEMENTO; }
        if (type == "result") { return Message_Type::RESULT; }
        if (type == "move") { return Message_Type::MOVE; }

        // If the type was none of the above an error occured
        return Message_Type::UNKNOWN;
    }

    

    Game::GameState getGameStateFromMessage(const std::string &message) {
        Game::GameState gameState;
        pugi::xml_document messageDocument;
        messageDocument.load_string(message.data());

        pugi::xml_node room = messageDocument.child("room");
        for (pugi::xml_attribute stateAttr : room.child("data").child("state").attributes()) {
            std::string attrName(stateAttr.name());
            if (attrName == "turn") {
                gameState.setTurn(stateAttr.as_int());
            } else if (attrName == "startTeam") {
                if (stateAttr.as_string() == "ONE") {
                    gameState.currentTeam = 0;
                } else {
                    gameState.currentTeam = 1;
                }
            } 
        }

        Game::Board board = Game::Board();
        int x = 0;
        for (pugi::xml_node stateNode : room.child("data").child("state").child("board").children()) {
            int y = 0;
            for (pugi::xml_attribute fieldAttr : stateNode.attributes()) {
                std::string val = fieldAttr.as_string();
                if (val == "0") { board.board[x][y] = '0'; }
                else if (val == "1") { board.board[x][y] = '1'; }
                else if (val == "2") { board.board[x][y] = '2'; }
                else if (val == "3") { board.board[x][y] = '3'; }
                else if (val == "ONE") { board.board[x][y] = '4'; }
                else if (val == "TWO") { board.board[x][y] = '5'; }
                y++;
            }
            x++;
        }
        gameState.setBoard(board);
        x = 0;
        for (pugi::xml_node stateNode : room.child("data").child("state").child("fishes").children()) {
            if (x == 0) { gameState.setFishesOne(stateNode.attribute("int").as_int()); }
            else if (x == 1) { gameState.setFishesTwo(stateNode.attribute("int").as_int()); }
            x++;
        }
        
        return gameState;
    }
} // namespace Game_Communication
