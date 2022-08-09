#include "logic.h"

class RandomLogic : public Logic::Logic
{
private:
public:
    RandomLogic() : Logic::Logic() { }
    
    Game::Move getMove(Game::GameState gameState) {
        std::vector<Game::Move> possibleMoves = gameState.getPossibleMoves();

        return possibleMoves[0];
    }
};

