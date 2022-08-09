#pragma once

#include "move.h"
#include "board.h"

#include <vector>

namespace Game {
	class GameState {
	private:
		Board board;
		int turn;
		int fishCount[2];
		int unsetPenguins[2];
	public:
		GameState();
		GameState(GameState& other);

		/**
		 * @brief Gets all Possible Moves for the current team 
		 * 
		 * @return std::vector<Move> All moves that can be made.
		 */
		std::vector<Move> getPossibleMoves();

		/**
		 * @brief Gets all Possible Moves for the current team 
		 * 
		 * @param team The team for which the moves will be searched.
		 * @return std::vector<Move> All moves that can be made.
		 */
		std::vector<Move> getPossibleMoves(bool team);

		/**
		 * @brief Performs a move on the current gamestate.
		 * 		  Does *not* check if the move is legal.
		 * 
		 * @param move 
		 */
		void performMove(Move move);

		/** @brief 0 = ONE, 1 = TWO */
		bool currentTeam;

		/**
		 * @brief Checks if the given team can still move.
		 * 
		 * @param team 
		 * @return 'true' if the team can't move, 'false' if it can
		 */
		bool immovable(bool team);

		/**
		 * @brief Checks if the game is over, e.g. no team can move anymore.
		 * 
		 * @return 'true' if no team can move, false otherwise.
		 */
		bool isOver();

		void setTurn(int newTurn);

		int getTurn();

		void setBoard(Board newBoard);

		Board getBoard();

		void setFishesOne(int count);

		int getFishesOne();

		void setFishesTwo(int count);

		int getFishesTwo();

		int getUnsetPenguinsOne();

		void setUnsetPenguinsOne(int count);

		int getUnsetPenguinsTwo();

		void setUnsetPenguinsTwo(int count);
	};
}