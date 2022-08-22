#include "logic.h"

namespace Logic
{
    Logic::Logic() {};

    Game::Move Logic::get_move(Game::GameState& gamestate) {
        // Get all moves that are currently possible.
        std::vector<Game::Move> possibleMoves = gamestate.get_possible_moves();

        if (possibleMoves.size() == 0) {
            std::cout << "ERROR: NO MOVES FOUND!" << std::endl;
            throw;
        }

        // Return the chosen move, in this case the first move in the vector.
        return possibleMoves[0];
    }
    
} // namespace Logic
