#include "client.h"
#include "logic.h"
#include "custom_logic.cpp"

int main(int argc, char *argv[]) {
    // Choose your custom logic here
    RandomLogic logic;
    Client::Game_Client client(logic);
    if (argc == 3) {
        std::string ip(argv[1]);
        unsigned short port = (unsigned short ) atoi(argv[2]);
        client.Start(ip, port);
    } else {
        client.Start("127.0.0.1", 13051);
    }
}