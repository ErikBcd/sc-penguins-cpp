#include "message_handler.h"

namespace MessageHandling
{
    using namespace Game;
    Message_Type MessageHandler::getMessageTypeFromTag(const std::string &tagname) {
        if (tagname == "welcomeMessage") { return Message_Type::WELCOME_MESSAGE; }
        if (tagname == "moveRequest") { return Message_Type::MOVE_REQUEST; }
        if (tagname == "memento") { return Message_Type::MEMENTO; }
        if (tagname == "result") { return Message_Type::RESULT; }
        if (tagname == "move") { return Message_Type::MOVE; }

        // If the type was none of the above an error occured
        return Message_Type::UNKNOWN;
    }

    std::vector<SC_Message> MessageHandler::splitMessage(const std::string &message) {
        std::string editedMsg = "<root>\n" + message + "</root>";
        pugi::xml_document messageDocument;
        messageDocument.load_string(editedMsg.data());
        pugi::xml_node subMessages = messageDocument.child("root");

        std::vector<SC_Message> messages;

        for (pugi::xml_node sub : subMessages.children()) {
            xml_string_writer writer;
            sub.print(writer, "");
            pugi::xml_node subsub = sub.child("data");
            Message_Type type = getMessageTypeFromTag(subsub.first_attribute().as_string());
            messages.push_back(SC_Message(writer.result, type));
        }
    }

    std::string MessageHandler::createJoinRequest() {
        return "<protocol>\n<join />";
    }

    std::string MessageHandler::createMoveMessage(const Game::Move &move, const std::string &roomID) {
        std::string message;
        if (move.is_set_move) {
            message = "<room roomId=\"" + roomID + "\">\n"
                        +"  <data class=\"move\">\n"
                        +"    <to x=\"" + std::to_string(move.destination.x) 
                        + "\" y=\"" + std::to_string(move.destination.y) + "\"/>"
                        +"  </data>"
                        +"</room>";
        } else {
            message = "<room roomId=\"" + roomID + "\">\n"
                        +"  <data class=\"move\">\n"
                        +"    <from x=\"" + std::to_string(move.start.x) 
                        + "\" y=\"" + std::to_string(move.start.y) + "\"/>"
                        +"    <to x=\"" + std::to_string(move.destination.x) 
                        + "\" y=\"" + std::to_string(move.destination.y) + "\"/>"
                        +"  </data>"
                        +"</room>";
        }
        return message;
    }

    GameState MessageHandler::getGameStateFromMessage(const std::string &message) {
        GameState gameState;
        pugi::xml_document messageDocument;
        messageDocument.load_string(message.data());
        pugi::xml_node state = messageDocument.child("room").child("data").child("state");

        gameState.setTurn(state.first_attribute().as_int());
        gameState.currentTeam = state.child("startTeam").text().as_string() == "TWO";
        
        pugi::xml_node board = state.child("board");
        Board b;
        int x = 0;
        int setPenguinsOne = 0;
        int setPenguinsTwo = 0;
        for (pugi::xml_node nx : board.children()) {
            int y = 0;
            for (pugi::xml_node ny : nx.children()) {
                if (ny.text().as_string() == "ONE") {
                    b.board[x][y] = 4;
                    setPenguinsOne++;
                } else if (ny.text().as_string() == "TWO")
                {
                    b.board[x][y] = 5;
                    setPenguinsTwo++;
                } else {
                    b.board[x][y] = ny.text().as_uint();
                }
                y++;
            }
            x++;
        }

        gameState.setBoard(b);
        gameState.setUnsetPenguinsOne(setPenguinsOne);
        gameState.setUnsetPenguinsTwo(setPenguinsTwo);

        x = 0;
        for (pugi::xml_node n : state.child("fishes").children()) {
            if (x == 0) {
                gameState.setFishesOne(n.text().as_uint());
            } else {
                gameState.setFishesTwo(n.text().as_uint());
            }
            x++;
        }

        return gameState;
}

    void MessageHandler::getWelcomeData(const std::string &message, std::string &room_ID, bool &team) {
        pugi::xml_document doc;
        doc.load_string(message.data());
        room_ID = doc.first_attribute().as_string();
        team = doc.child("data").attribute("color").as_string() == "TWO";
    }

    GameResult MessageHandler::getResult(const SC_Message &msg) {
        pugi::xml_document doc;
        doc.load_string(msg.getContent().data());
        pugi::xml_node scores = doc.child("room").child("data").child("scores");
        GameResult result;
        int x = 0;
        for (pugi::xml_node n : scores.children()) {
            if (x==0) {
                result.playerOneCause = n.child("score").attribute("cause").as_string();
                result.playerOneReason = n.child("score").attribute("reason").as_string();
                int y = 0;
                for (pugi::xml_node points : n.child("score").children()) {
                    if (y==0) {
                        result.playerOneWinningPoints = points.text().as_int();
                    } else {
                        result.playerOneAveragePoints = points.text().as_int();
                    }
                    y++;
                }
            } else {
                result.playerTwoCause = n.child("score").attribute("cause").as_string();
                result.playerTwoReason = n.child("score").attribute("reason").as_string();
                int y = 0;
                for (pugi::xml_node points : n.child("score").children()) {
                    if (y==0) {
                        result.playerTwoWinningPoints = points.text().as_int();
                    } else {
                        result.playerTwoAveragePoints = points.text().as_int();
                    }
                    y++;
                }
            }
            x++;
        }

        result.winner = (doc.child("data").child("winner").first_attribute().as_string() == "TWO");

        return result;
    }
} // namespace MessageHandling
