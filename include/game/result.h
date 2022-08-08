#pragma once

#include <string>

namespace Game {
	class GameResult
	{
	public:
		GameResult();

		bool winner;

		std::string playerOneReason;
		std::string playerOneCause;
		int playerOneWinningPoints;
		int playerOneAveragePoints;

		std::string playerTwoReason;
		std::string playerTwoCause;
		int playerTwoWinningPoints;
		int playerTwoAveragePoints;

		std::string toString();
	};
}