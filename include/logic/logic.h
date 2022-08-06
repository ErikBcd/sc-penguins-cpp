#pragma once

#include "../game/move.h"
#include "../game/gameState.h"

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