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
        
        /**
         * @brief Called when the server expects a move. 
         *        Should return a move, in less then 2s.
         * 
         * @param gamestate The current gamestate
         * @return Game::Move Set move or drag move.
         */
        virtual Game::Move get_move(Game::GameState gamestate);
    };
}