#include "result.h"

namespace Game
{
    std::string GameResult::toString() {
        std::stringstream ss;
        ss << "Winner: " << ((winner) ? "TWO\n" : "ONE\n") 
           << "Player ONE Points: " << playerOneWinningPoints << " Average: " << playerOneAveragePoints << "\n"
           << "Player ONE Reason/Cause: " << playerOneReason << "/" << playerOneCause << "\n"
           << "Player TWO Points: " << playerTwoWinningPoints << " Average: " << playerTwoAveragePoints << "\n"
           << "Player TWO Reason/Cause: " << playerTwoReason << "/" << playerTwoCause << "\n";
        return ss.str();
    }
} // namespace Game
