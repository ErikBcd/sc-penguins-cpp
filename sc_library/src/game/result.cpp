#include "result.h"

namespace Game
{
    GameResult::GameResult() {}
    std::string GameResult::to_string() {
        std::stringstream ss;
        ss << "Winner: " << ((winner) ? "TWO\n" : "ONE\n") 
           << "Player ONE Points: " << player_one_winning_points << " Average: " << player_one_average_points << "\n"
           << "Player ONE Reason/Cause: " << player_one_Reason << "/" << player_one_cause << "\n"
           << "Player TWO Points: " << player_two_winning_points << " Average: " << player_two_average_points << "\n"
           << "Player TWO Reason/Cause: " << player_two_reason << "/" << player_two_cause << "\n";
        return ss.str();
    }
} // namespace Game
