#pragma once

namespace Coordinates {
	class Coordinate {
	public:
		int x;
		int y;

		Coordinate(int xIn, int yIn);

		bool isDoubleHex;

		Coordinate toDoubleHex();
		Coordinate toArrayCoordinate();
	};

	/**
	 *	@brief The distance between two Coordinates.
	 */
	class GameVector {
	public:
		int x;
		int y;

		GameVector(int dx, int dy);

		/** 
		 * @brief Area of a rectangle, spanned by the diagonal of the vector.
		 */
		int getArea();

		int getComparableLength();

		double getLength();

		void times(int scalar);

		int compareTo(GameVector other);

		struct DoubledHex;

		struct VectorDirections
		{
			/*GameVector LEFT = GameVector(+2, 0);
			GameVector RIGHT;
			GameVector UP_LEFT;
			GameVector UP_RIGHT;
			GameVector DOWN_LEFT;
			GameVector DOWN_RIGHT;
			
			GameVector directions[6];*/
			/*static GameVector LEFT = GameVector(+2, 0);
			static GameVector RIGHT = GameVector(-2, 0);
			static GameVector UP_LEFT = GameVector(-1, -1);
			static GameVector UP_RIGHT = GameVector(+1, -1);
			static GameVector DOWN_LEFT = GameVector(-1, +1);
			static GameVector DOWN_RIGHT = GameVector(+1, +1);
		
			static GameVector directions[6] = { LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };*/
		};
	private:
	};

	
}