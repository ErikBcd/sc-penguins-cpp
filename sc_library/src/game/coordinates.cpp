#include "coordinates.h"
#include <cmath>

namespace Coordinates {
	Coordinate::Coordinate() {}
	Coordinate::Coordinate(int xIn, int yIn, bool doubleHex) {
		this->x = xIn;
		this->y = yIn;
		is_double_hex = doubleHex;
	}

	Coordinate Coordinate::to_double_hex() {
		int xo = (y % 2 == 0) ? this->x * 2 : 1 + (this->x * 2);
		return Coordinate(xo, this->y);
	}

	Coordinate Coordinate::to_array_coordinate() {
		return Coordinates::Coordinate(this->x / 2, this->y, false);
	}

	Coordinate Coordinate::operator+(const Coordinate& other) {
		if (this->is_double_hex && !other.is_double_hex) {
			throw "Error: Coordinates are of different types!";
		}
		return Coordinate(this->x + other.x, this->y + other.y);
	}
}