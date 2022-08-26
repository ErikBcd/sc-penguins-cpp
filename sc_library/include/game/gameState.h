#pragma once

#include "move.h"
#include "board.h"

#include <vector>

namespace Game {
	class GameState {
	private:
		Board board;
		int turn;
		int fish_count[2];
		int set_penguins[2];
	public:
		GameState();
		GameState(GameState& other);

		/** @brief 0 = ONE, 1 = TWO */
		bool current_team;

		/**
		 * @brief Gets all Possible Moves for the current team 
		 * 
		 * @return std::vector<Move> All moves that can be made.
		 */
		std::vector<Move> get_possible_moves();

		/**
		 * @brief Gets all Possible Moves for the current team 
		 * 
		 * @param team The team for which the moves will be searched.
		 * @return std::vector<Move> All moves that can be made.
		 */
		std::vector<Move> get_possible_moves(bool team);

		/**
		 * @brief Performs a move on the current gamestate.
		 * 		  Does *not* check if the move is legal.
		 * 
		 * @param move 
		 */
		void perform_move(Move move);

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
		bool is_over();

		void set_turn(int newTurn);

		int get_turn();

		void set_board(Board newBoard);

		Board get_board();

		void set_fishes_one(int count);

		int get_fishes_one();

		void set_fishes_two(int count);

		int get_fishes_two();

		/**
		 * @brief Returns the number of penguins on the field of player one.
		 * 
		 */
		int get_penguins_one();

		/**
		 * @brief Sets the number of penguins on the field of player one.
		 * 
		 * @param count Number of penguins.
		 */
		void set_penguins_one(int count);

		/**
		 * @brief Returns the number of penguins on the field of player two.
		 * 
		 */
		int get_penguins_two();

		/**
		 * @brief Sets the number of penguins on the field of player two.
		 * 
		 * @param count Number of penguins.
		 */
		void set_penguins_two(int count);
	};
}