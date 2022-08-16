#pragma once

#include "coordinates.h"

namespace Game {
	class Move {
		public:
			Move();
			/**
			 * @brief Constructs a new Move object with a start and an end.
			 * 
			 * @param mStart Start of the move in double hex coords. Empty if it's a set move.
			 * @param mDest End of the move in double hex coords.
			 * @param set_move Default: false. Set true if the move is a set move.
			 */
			Move(Coordinates::Coordinate mStart, Coordinates::Coordinate mDest, bool set_move = false);
			
			/**
			 * @brief Start of the move in double hex coordinates.
			 * 		  Empty if move is a set move.
			 */
			Coordinates::Coordinate start;
			
			/**
			 * @brief Destination of the move in double hex coordinates.
			 */
			Coordinates::Coordinate destination;

			/**
			 * @brief true if the move is a set move, false if it's a drag move.
			 * 
			 */
			bool is_set_move;
	};
}