#pragma once

#include <iostream>
#include <boost/asio.hpp>

namespace MessageHandling {
    /**
     * @brief Functions for setting up and using a connection to a game-server.
     */
    class TCP_Connection {
        private:
            /**
             * @brief io_service needed by boost asio
             */
            boost::asio::io_service io_service;
            
            /**
             * @brief TCP IP socket.
             */
            boost::asio::ip::tcp::socket socket_ {io_service};

            /**
             * @brief Buffer for received messages, set when something was received.
             */
            boost::asio::streambuf received;
        public:
            TCP_Connection();

            /**
             * @brief Sends a message to the connected server.
             * 
             * @param message The xml-message as a string.
             */
            void send(const std::string &message);

            /**
             * @brief Receives a message from the connected server.
             * 
             * @return std::string The message in question.
             */
            std::string receive();

            /**
             * @brief Connects to a server, specified by an IP adress and a port.
             * 
             * @param ip_address IP adress of the server.
             * @param port Port of the server.
             */
            void connect(std::string ip_address = "127.0.0.1", unsigned short port = 13051);

            /**
             * @brief Disconnects the client-server connection.
             */
            void disconnect();
    };
}