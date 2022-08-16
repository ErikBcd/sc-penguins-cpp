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
    Game::Move get_move(Game::GameState gameState) {
        // Get all moves that are currently possible.
        std::vector<Game::Move> possibleMoves = gameState.get_possible_moves();

        if (possibleMoves.size() == 0) {
            std::cout << "ERROR: NO MOVES FOUND!" << std::endl;
            throw;
        }

        /// TESTING AREA
        std::cout << "====================================================\n";
        std::cout <<    "OLD GameState Test\n" << 
                        "Turn: " << gameState.get_turn() << 
                        "\nCurrent Team: " << ((gameState.current_team) ? "TWO" : "ONE") <<
                        "\nFishCount ONE=" << gameState.get_fishes_one() <<
                        "\nPenguins Set ONE=" << gameState.get_penguins_one() <<
                        "\nFishCount TWO=" << gameState.get_fishes_two() <<
                        "\nPenguins Set TWO=" << gameState.get_penguins_two() << std::endl; 
        std::cout << "OLD Board:\n" << gameState.get_board().to_string();

        std::cout << "====================================================\n";
        
        gameState.perform_move(possibleMoves[0]);
        std::cout <<    "NEW GameState Test\n" << 
                        "Turn: " << gameState.get_turn() << 
                        "\nCurrent Team: " << ((gameState.current_team) ? "TWO" : "ONE") <<
                        "\nFishCount ONE=" << gameState.get_fishes_one() <<
                        "\nPenguins Set ONE=" << gameState.get_penguins_one() <<
                        "\nFishCount TWO=" << gameState.get_fishes_two() <<
                        "\nPenguins Set TWO=" << gameState.get_penguins_two() << std::endl; 
        std::cout << "NEW Board:\n" << gameState.get_board().to_string();
        // Return the chosen move, in this case the first move in the vector.
        return possibleMoves[0];
    }
};

