#include "client.h"
#include "logic.h"
#include "custom_logic.cpp"

int main(int argc, char *argv[]) {
    Logic::Logic logic = RandomLogic();
    Client::Game_Client client(logic);
    client.Start(argc, argv);
}