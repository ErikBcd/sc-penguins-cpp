#include "coordinates.h"
#include <cmath>

namespace Coordinates {
	Coordinate::Coordinate() {}
	Coordinate::Coordinate(int xIn, int yIn, bool doubleHex) {
		this->x = xIn;
		this->y = yIn;
		isDoubleHex = doubleHex;
	}

	Coordinate Coordinate::toDoubleHex() {
		int xo = (y % 2 == 0) ? this->x * 2 : 1 + (this->x * 2);
		return Coordinate(xo, this->y);
	}

	Coordinate Coordinate::toArrayCoordinate() {
		return Coordinates::Coordinate((int)this->x / 2, this->y);
	}

	Coordinate Coordinate::operator+(const Coordinate& other) {
		if (this->isDoubleHex && !other.isDoubleHex) {
			throw "Error: Coordinates are of different types!";
		}
		return Coordinate(this->x + other.x, this->y + other.y);
	}
}