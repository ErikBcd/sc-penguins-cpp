#pragma once

namespace Coordinates {
	class Coordinate {
	public:
		int x;
		int y;

		Coordinate();

		Coordinate(int xIn, int yIn, bool doubleHex = true);

		bool is_double_hex;

		Coordinate to_double_hex();
		Coordinate to_array_coordinate();

		Coordinate operator+(const Coordinate& other);
	};

	struct DoubleHexDirections
	{
		Coordinate LEFT = Coordinate(+2, 0);
		Coordinate RIGHT = Coordinate(-2, 0);
		Coordinate UP_LEFT = Coordinate(-1, -1);
		Coordinate UP_RIGHT = Coordinate(+1, -1);
		Coordinate DOWN_LEFT = Coordinate(-1, +1);
		Coordinate DOWN_RIGHT = Coordinate(+1, +1);
		Coordinate directions[6] = { LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };
	};
}