#include "message_handler.h"

namespace MessageHandling
{
    using namespace Game;

    MessageHandler::MessageHandler() {}

    Message_Type MessageHandler::get_type_from_tag(const std::string &tagname) {
        if (tagname == "welcomeMessage") { return Message_Type::WELCOME_MESSAGE; }
        if (tagname == "moveRequest") { return Message_Type::MOVE_REQUEST; }
        if (tagname == "memento") { return Message_Type::MEMENTO; }
        if (tagname == "result") { return Message_Type::RESULT; }
        if (tagname == "move") { return Message_Type::MOVE; }

        // If the type was none of the above an error occured
        return Message_Type::UNKNOWN;
    }

    SC_Message MessageHandler::create_message(const std::string &message) {
        pugi::xml_document doc;
        doc.load_string(message.data());
        Message_Type type = get_type_from_tag(doc.child("room").child("data").first_attribute().as_string());

        return SC_Message(message, type);
    }

    std::vector<SC_Message> MessageHandler::split_message(const std::string &message) {
        std::string editedMsg = "<root>\n" + message + "</root>";
        pugi::xml_document messageDocument;
        messageDocument.load_string(editedMsg.data());
        pugi::xml_node subMessages = messageDocument.child("root");

        std::vector<SC_Message> messages;

        for (pugi::xml_node sub : subMessages.children()) {
            xml_string_writer writer;
            sub.print(writer, "");
            pugi::xml_node subsub = sub.child("data");
            Message_Type type = get_type_from_tag(subsub.first_attribute().as_string());
            messages.push_back(SC_Message(writer.result, type));
        }

        return messages;
    }

    std::string MessageHandler::create_join_request() {
        return "<protocol>\n<join />";
    }

    std::string MessageHandler::create_move_message(const Game::Move &move, const std::string &roomID) {
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

    GameState MessageHandler::get_GameState_from_message(const std::string &message) {
        GameState gameState;
        pugi::xml_document messageDocument;
        messageDocument.load_string(message.data());
        pugi::xml_node state = messageDocument.child("room").child("data").child("state");

        gameState.set_turn(state.attribute("turn").as_int());
        
        pugi::xml_node board = state.child("board");
        Board b;
        int x = 0;
        int setPenguinsOne = 0;
        int setPenguinsTwo = 0;
        for (pugi::xml_node nx : board.children()) {
            int y = 0;
            for (pugi::xml_node ny : nx.children()) {
                if (std::string("ONE").compare(ny.text().as_string()) == 0) {
                    b.board[y][x] = b.PLAYER_ONE;
                    setPenguinsOne++;
                } else if (std::string("TWO").compare(ny.text().as_string()) == 0)
                {
                    b.board[y][x] = b.PLAYER_TWO;
                    setPenguinsTwo++;
                } else {
                    b.board[y][x] = ny.text().as_uint();
                }
                y++;
            }
            x++;
        }

        gameState.set_board(b);
        gameState.set_penguins_one(setPenguinsOne);
        gameState.set_penguins_two(setPenguinsTwo);

        x = 0;
        for (pugi::xml_node n : state.child("fishes").children()) {
            if (x == 0) {
                gameState.set_fishes_one(n.text().as_uint());
            } else {
                gameState.set_fishes_two(n.text().as_uint());
            }
            x++;
        }

        return gameState;
}

    void MessageHandler::get_welcome_data(const std::string &message, std::string &room_ID, bool &team) {
        pugi::xml_document doc;
        doc.load_string(message.data());
        room_ID = doc.child("room").first_attribute().as_string();
        team = (std::string("TWO").compare(
                    doc.child("room")
                        .child("data").attribute("color").as_string()) == 0);
        //team = doc.child("room").child("data").attribute("color").as_string() == "TWO";
    }

    GameResult MessageHandler::get_result(const SC_Message &msg) {
        pugi::xml_document doc;
        doc.load_string(msg.get_content().data());
        pugi::xml_node scores = doc.child("room").child("data").child("scores");
        GameResult result;
        int x = 0;
        for (pugi::xml_node n : scores.children()) {
            if (x==0) {
                result.player_one_cause = n.child("score").attribute("cause").as_string();
                result.player_one_Reason = n.child("score").attribute("reason").as_string();
                int y = 0;
                for (pugi::xml_node points : n.child("score").children()) {
                    if (y==0) {
                        result.player_one_winning_points = points.text().as_int();
                    } else {
                        result.player_one_average_points = points.text().as_int();
                    }
                    y++;
                }
            } else {
                result.player_two_cause = n.child("score").attribute("cause").as_string();
                result.player_two_reason = n.child("score").attribute("reason").as_string();
                int y = 0;
                for (pugi::xml_node points : n.child("score").children()) {
                    if (y==0) {
                        result.player_two_winning_points = points.text().as_int();
                    } else {
                        result.player_two_average_points = points.text().as_int();
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
