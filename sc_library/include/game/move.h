#pragma once

#include "coordinates.h"

namespace Game {
	class Move {
		public:
			Move();
			Move(Coordinates::Coordinate mStart, Coordinates::Coordinate mDest, bool set_move = false);
			Coordinates::Coordinate start;
			Coordinates::Coordinate destination;

			bool is_set_move;
	};
}