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
} // namespace MessageHandler
