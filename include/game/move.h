#pragma once

#include "util/coordinates.h"

namespace Game {
	class Move {
		public:
			Move();
			Move(Coordinates::Coordinate mStart, Coordinates::Coordinate mDest);
			Coordinates::Coordinate start;
			Coordinates::Coordinate destination;
	};
}