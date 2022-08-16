#include "logic.h"
#include <chrono>

/**
 * @brief A subclass of a game logic.
 *        Here you can implement your own logic, which will pick the moves in the game.
 * 
 */
class RandomLogic : public Logic::Logic
{
private:
public:
    
    /**
     * @brief This method will be called once the server requests a move.
     * 
     * @param gameState The current state of the game. 
     * @return Game::Move 
     */
    Game::Move getMove(Game::GameState gameState) {
        // Get all moves that are currently possible.
        std::vector<Game::Move> possibleMoves = gameState.getPossibleMoves();

        if (possibleMoves.size() == 0) {
            std::cout << "ERROR: NO MOVES FOUND!" << std::endl;
            throw;
        }

        /// TESTING AREA
        std::cout << "====================================================\n";
        std::cout <<    "OLD GameState Test\n" << 
                        "Turn: " << gameState.getTurn() << 
                        "\nCurrent Team: " << ((gameState.currentTeam) ? "TWO" : "ONE") <<
                        "\nFishCount ONE=" << gameState.getFishesOne() <<
                        "\nPenguins Set ONE=" << gameState.getPenguinsOnFieldOne() <<
                        "\nFishCount TWO=" << gameState.getFishesTwo() <<
                        "\nPenguins Set TWO=" << gameState.getPenguinsOnFieldTwo() << std::endl; 
        std::cout << "OLD Board:\n" << gameState.getBoard().toString();

        std::cout << "====================================================\n";
        
        gameState.performMove(possibleMoves[0]);
        std::cout <<    "NEW GameState Test\n" << 
                        "Turn: " << gameState.getTurn() << 
                        "\nCurrent Team: " << ((gameState.currentTeam) ? "TWO" : "ONE") <<
                        "\nFishCount ONE=" << gameState.getFishesOne() <<
                        "\nPenguins Set ONE=" << gameState.getPenguinsOnFieldOne() <<
                        "\nFishCount TWO=" << gameState.getFishesTwo() <<
                        "\nPenguins Set TWO=" << gameState.getPenguinsOnFieldTwo() << std::endl; 
        std::cout << "NEW Board:\n" << gameState.getBoard().toString();
        // Return the chosen move, in this case the first move in the vector.
        return possibleMoves[0];
    }
};

