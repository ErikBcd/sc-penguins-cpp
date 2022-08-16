#pragma once

namespace Coordinates {
	class Coordinate {
	public:
		/** @brief x coordinate */
		int x;
		/** @brief y coordinate */
		int y;

		Coordinate();
		
		/**
		 * @brief Construct a new Coordinate Object from two indices
		 * 
		 * @param xIn x coordinate
		 * @param yIn y coordinate
		 * @param doubleHex Default: True. Determines if the coordinate is in double hex notation.
		 */
		Coordinate(int xIn, int yIn, bool doubleHex = true);

		/**
		 * @brief True if coordinates are in double hex notation.
		 * 
		 */
		bool is_double_hex;

		/**
		 * @brief Converts this coordinate to a double hex coordinate.
		 * 
		 * @return Coordinate in double hex notation.
		 */
		Coordinate to_double_hex();
		/**
		 * @brief Converts this coordinate to a standard coordinate that can be 
		 * 		  used to get fields in a standard 2d array.
		 * 
		 * @return Coordinate in standard notation.
		 */
		Coordinate to_array_coordinate();

		/**
		 * @brief + operator override for adding two coordinates.
		 * 
		 * @param other left hand argument
		 * @return Coordinate 
		 */
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