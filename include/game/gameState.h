#pragma once

#include "move.h"
#include "board.h"

#include <vector>

namespace Game {
	class GameState {
	private:
		Board board;
		int turn;
		Move lastMove;
		int fishesRed;
		int fishesBlue;
	public:
		GameState(GameState other);

		std::vector<Move> getPossibleMoves();

		void performMove(Move move);

		/** @brief 0 = Red, 1 = Blue */
		bool currentTeam;

		bool immovable(bool team);

		bool isOver();
	};
}