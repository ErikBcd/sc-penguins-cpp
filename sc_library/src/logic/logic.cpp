#include "logic.h"

namespace Logic
{
    Logic::Logic() {};

    Game::Move Logic::getMove(Game::GameState gamestate) {
        // Do something cool
        return gamestate.getPossibleMoves()[0];
    }
    
} // namespace Logic
