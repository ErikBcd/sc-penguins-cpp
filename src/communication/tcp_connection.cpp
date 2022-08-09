#include "tcp_connection.h"

namespace MessageHandling {
    using namespace boost::asio;
    TCP_Connection::TCP_Connection() { }

    void TCP_Connection::send(const std::string &message) {
        boost::system::error_code err;
        write(socket_, buffer(message), err);
        if (!err) {
            return;
        } else {
            std::cerr << "Failed sending: " << err.message() << std::endl;
        }
    }

    std::string TCP_Connection::receive() {
        boost::system::error_code err;
        // Using the receiving function of the former c++ client by sunfl0w, 
        // since I ran into trouble with this. Thanks! 
        std::size_t bytes_transferred = boost::asio::read_until(socket_, received, "</room>", err);
        if( err && err != boost::asio::error::eof ) {
            std::cerr << "Receiving message failed: " << err.message() << std::endl;
            return "";
        } else {
            std::string message{boost::asio::buffers_begin(received.data()), boost::asio::buffers_begin(received.data()) + bytes_transferred};
            received.consume(bytes_transferred);
            return message;
        }
    }

    void TCP_Connection::connect(std::string ip_address = "127.0.0.1", unsigned short port = 13051) {
        socket_.connect(ip::tcp::endpoint(ip::address::from_string(ip_address), port));
    }

    void TCP_Connection::disconnect() {
        socket_.close();
    }
}