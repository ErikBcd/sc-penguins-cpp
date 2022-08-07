#pragma once

#include <string>

namespace Game {
	class GameResult
	{
	public:
		GameResult();

	private:
		bool winner;

		bool ended_normally;

		std::string reason;
		std::string cause;

		int teamOnePoints;
		int teamTwoPoints;
	};
}