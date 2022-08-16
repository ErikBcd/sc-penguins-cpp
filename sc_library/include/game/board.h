#pragma once

#include "coordinates.h"
#include "move.h"

#include <vector>
#include <iostream>

#define BOARD_SIZE_X 8
#define BOARD_SIZE_Y 8

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
		bool is_valid_field(Coordinate c); 

		/**
		 * @brief Get the Moves from a position in a given direction.
		 * 
		 * @param start The starting position.
		 * @param dir The direction.
		 * @param moves Vector in which the moves will be stored.
		 */
		void get_moves_in_direction(Coordinate start, Coordinate dir, std::vector<Move>& moves);
	public:
		static const char EMPTY = 0;
		static const char ONE_FISH = 1;
		static const char TWO_FISHES = 2;
		static const char THREE_FISHES = 3;
		static const char PLAYER_ONE = 6;
		static const char PLAYER_TWO = 7;

		Board();

		Board(const Board& other);

		/**
		 * @brief The game board as a X * Y char array.
		 * 
		 */
		char board[BOARD_SIZE_X][BOARD_SIZE_Y];

		/**
		 * @brief Checks if the given coordinate is in Bounds
		 * 
		 * @param c 
		 * @return true If the coordinate is in the bounds defined in
		 * 		   BOARD_SIZE_X and BOARD_SIZE_Y
		 * @return false otherwise
		 */
		bool coordinate_in_bounds(Coordinates::Coordinate c);

		/**
		 * @brief Gets the field from the board at the position of c.
		 * 
		 * @param c Coordinates of the field.
		 * @return Value of the field as a char.
		 */
		char get_field(Coordinates::Coordinate c);

		/**
		 * @brief Sets a field on the board to a new value.
		 * 
		 * @param c The coordinate of the field.
		 * @param field The new value.
		 */
		void set_field(Coordinates::Coordinate c, char field);

		/**
		 * @brief Get the Possible Moves From a specific field.
		 * 
		 * @param c The starting position.
		 * @param moves A vector of moves that will be used as storage.
		 */
		void get_possible_moves_from(Coordinate c, std::vector<Move>& moves);

		/**
		 * @brief Get the fields fith a single fish on them.
		 * 
		 * @param moves Set-Moves that land on fields with single fish on them.
		 */
		void get_fields_with_single_fish(std::vector<Move>& moves);

		/**
		 * @brief Get the positions of the penguins of the given team
		 * 
		 * @param team Team that the penguins belong to.
		 * @return std::vector<Coordinate> Coordinates of the penguins. 
		 */
		std::vector<Coordinate> get_penguin_positions(bool team);

		/**
		 * @brief Create a string that represents the board.
		 * 
		 */
		std::string to_string();
	};
}