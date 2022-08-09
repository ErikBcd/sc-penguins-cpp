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
        
        Game::Move getMove(Game::GameState gamestate);
    };
}