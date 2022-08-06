#pragma once

#include "util/coordinates.h"

namespace Game {
	class Move {
		public:
			Coordinates::Coordinate start;
			Coordinates::Coordinate destination;
	};
}