#pragma once

#include "move.h"
#include "gameState.h"

namespace Logic {
    class Logic
    {
    private:
        /* data */
    public:
        Logic(/* args */);
        
        virtual Game::Move get_move(Game::GameState gamestate);
    };
}