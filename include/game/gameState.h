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
		int fishesOne;
		int fishesTwo;
	public:
		GameState();
		GameState(const GameState& other);

		std::vector<Move> getPossibleMoves();

		void performMove(Move move);

		void setTurn(int turn);

		void setBoard(Board board);

		void setFishesOne(int count);

		void setFishesTwo(int count);

		/** @brief 0 = ONE, 1 = TWO */
		bool currentTeam;

		bool immovable(bool team);

		bool isOver();
	};
}