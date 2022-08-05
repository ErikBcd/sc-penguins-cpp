#include "board.h"

namespace Game {
	char Board::getField(Coordinates::Coordinate c) {
		if (c.isDoubleHex) {
			Coordinates::Coordinate cd = c.toArrayCoordinate();
			return board[cd.x][cd.y];
		}

		return board[c.x][c.y];
	}

	std::vector<Move> Board::getPossibleMovesFrom(Coordinates::Coordinate c) {
		std::vector<Move> moves;
		//for (Coordinates::GameVector v : Coordinates::VectorDirections::directions) {

		//}
	}
}