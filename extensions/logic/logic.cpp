#include "../../include/logic/logic.h"

class RandomLogic : public Logic::Logic
{
private:
    /* data */
public:
    RandomLogic() : Logic::Logic() { }
    
    Game::Move getMove(Game::GameState gameState) {
        std::vector<Game::Move> possibleMoves = gameState.getPossibleMoves();

        return possibleMoves[0];
    }
};

