#pragma once

#include <string>
#include <sstream>

namespace Game {
	class GameResult
	{
	public:
		GameResult();

		bool winner;

		std::string player_one_Reason;
		std::string player_one_cause;
		int player_one_winning_points;
		int player_one_average_points;

		std::string player_two_reason;
		std::string player_two_cause;
		int player_two_winning_points;
		int player_two_average_points;

		std::string to_string();
	};
}