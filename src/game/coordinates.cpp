#include "coordinates.h"
#include <cmath>

namespace Coordinates {
	Coordinate::Coordinate(int xIn, int yIn) {
		this->x = xIn;
		this->y = yIn;
	}

	Coordinate Coordinate::toDoubleHex() {
		int xo = (y % 2 == 0) ? this->x * 2 : 1 + (this->x * 2);
		return Coordinate(xo, this->y);
	}

	Coordinate Coordinate::toArrayCoordinate() {
		return Coordinates::Coordinate((int)this->x / 2, this->y);
	}

	GameVector::GameVector(int dx, int dy) {
		this->x = dx;
		this->y = dy;
	}

	int GameVector::getArea() {
		return abs(x * y);
	}

	int GameVector::getComparableLength() {
		return (x * x) + (y * y);
	}

	double GameVector::getLength() {
		return sqrt(this->getComparableLength());
	}

	void GameVector::times(int scalar) {
		this->x *= scalar;
		this->y *= scalar;
	}

	int GameVector::compareTo(GameVector other) {
		return this->getComparableLength() - other.getComparableLength();
	}

	struct GameVector::DoubledHex
	{
		GameVector diagonals[4] = {	GameVector(-1, -1),
									GameVector(1, 1),
									GameVector(-1, 1),
									GameVector(1, -1) };
		GameVector cardinals[4] = {	GameVector(-1, 0),
									GameVector(1, 0),
									GameVector(0, 1),
									GameVector(0, -1) };
	};

	struct GameVector::VectorDirections {
		GameVector LEFT = GameVector(+2, 0);
		GameVector RIGHT = GameVector(-2, 0);
		GameVector UP_LEFT = GameVector(-1, -1);
		GameVector UP_RIGHT = GameVector(+1, -1);
		GameVector DOWN_LEFT = GameVector(-1, +1);
		GameVector DOWN_RIGHT = GameVector(+1, +1);

		GameVector directions[6] = { LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };
	};
	
}