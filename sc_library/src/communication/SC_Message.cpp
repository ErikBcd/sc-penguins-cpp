#include "message_handler.h"

namespace MessageHandling
{
    SC_Message::SC_Message() {}

    SC_Message::SC_Message(const std::string &msg_content, const Message_Type &msg_type) {
        this->content = msg_content;
        this->type = msg_type;
    }

    Message_Type SC_Message::getType() const {
        return type;
    }

    std::string SC_Message::getContent() const {
        return content;
    }

    std::string SC_Message::typeAsString() const {
        switch (type)
        {
        case Message_Type::MEMENTO :
            return "MEMENTO";
        case Message_Type::MOVE :
            return "MOVE";
        case Message_Type::MOVE_REQUEST :
            return "MOVE_REQUEST";
        case Message_Type::RESULT :
            return "RESULT";
        case Message_Type::UNKNOWN :
            return "UNKNOWN";
        case Message_Type::WELCOME_MESSAGE :
            return "WELCOME_MESSAGE";
        default:
            return "WTF";
        }
    }
} // namespace MessageHandler
