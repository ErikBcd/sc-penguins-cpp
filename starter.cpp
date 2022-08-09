#include "./include/client/client.h"
#include "./extensions/logic/logic.cpp"

int main(int argc, char *argv[]) {
    Logic::Logic logic = RandomLogic();
    Client::Game_Client client(logic);
    client.Start(argc, argv);
}