#pragma once

#include "coordinates.h"
#include "move.h"

#include <vector>

#define BOARD_SIZE_X 8
#define BOARD_SIZE_Y 8

#define EMPTY 0
#define ONE_FISH 1 
#define TWO_FISHES 2 
#define THREE_FISHES 3 
#define PLAYER_ONE 4
#define PLAYER_TWO 5

namespace Game {
	using namespace Coordinates;
	class Board {
	private:
		/**
		 * @brief Checks if a given Double Hex Coordinate is a valid field.
		 * 		  Has to be in bounds and on a non-empty field.
		 * 
		 * @param c 
		 * @return true 
		 * @return false 
		 */
		bool isValidField(Coordinate c); 

		/**
		 * @brief Get the Moves from a position in a given direction.
		 * 
		 * @param start The starting position.
		 * @param dir The direction.
		 * @param moves Vector in which the moves will be stored.
		 */
		void getMovesInDirection(Coordinate &start, Coordinate dir, std::vector<Move>& moves);
	public:
		Board();

		/**
		 * @brief The game board as a X * Y char array.
		 * 
		 */
		char board[BOARD_SIZE_X][BOARD_SIZE_Y];

		/**
		 * @brief Gets the field from the board at the position of c.
		 * 
		 * @param c Coordinates of the field.
		 * @return Value of the field as a char.
		 */
		char getField(Coordinates::Coordinate c);

		/**
		 * @brief Get the Possible Moves From a specific field.
		 * 
		 * @param c The starting position.
		 * @param moves A vector of moves that will be used as storage.
		 */
		void getPossibleMovesFrom(Coordinate c, std::vector<Move>& moves);
	};
}