#include "board.h"
#include <vector>

namespace Game {
	Board::Board() {}

	Board::Board(const Board& other) {
		for (int x = 0; x < BOARD_SIZE_X; x++) {
			for (int y = 0; y < BOARD_SIZE_Y; y++) {
				this->board[x][y] = other.board[x][y];
			}
		}
	}
	
	bool Board::coordinateIsInBounds(Coordinates::Coordinate c) {
		return (c.x >= 0 && c.y >= 0) && (c.x < BOARD_SIZE_X && c.y < BOARD_SIZE_Y);
	}

	char Board::getField(Coordinates::Coordinate c) {
		if (c.isDoubleHex) {
			Coordinates::Coordinate cd = c.toArrayCoordinate();
			if (coordinateIsInBounds(cd)) {
				return board[cd.x][cd.y];
			} else {
				throw "Coordinate is out of bounds!";
			}
		}
		
		if (coordinateIsInBounds(c)) {
			return board[c.x][c.y];
		} else {
			throw "Coordinate is out of bounds!";
		}
	}

	void Board::setField(Coordinates::Coordinate c, char field) {
		if (c.isDoubleHex) {
			Coordinates::Coordinate cd = c.toArrayCoordinate();
			if (coordinateIsInBounds(cd)) {
				board[cd.x][cd.y] = field;
				return;
			} else {
				throw "Coordinate is out of bounds!";
			}
		}

		if (coordinateIsInBounds(c)) {
			board[c.x][c.y] = field;
			return;
		} else {
			throw "Coordinate is out of bounds!";
		}
	}

	bool Board::isValidField(Coordinate c) {
		Coordinate arrCoord = (c.isDoubleHex) ? c.toArrayCoordinate() : c;

		if (!coordinateIsInBounds(arrCoord)) {
			return false;
		}

		return (board[arrCoord.x][arrCoord.y] != EMPTY) 
			&& (board[arrCoord.x][arrCoord.y] != PLAYER_ONE)
			&& (board[arrCoord.x][arrCoord.y] != PLAYER_TWO);
	}

	void Board::
		getMovesInDirection(Coordinates::Coordinate& start, Coordinates::Coordinate dir, std::vector<Move>& moves) {
		Coordinates::Coordinate c = (start.isDoubleHex) ? start : start.toDoubleHex();
		while (isValidField(c)) {
			// TODO: Check if the server wants double hex coordinates or standard coords..
			moves.push_back(Move(start, c));
			c = dir + c;
		}
	}

	void Board::getPossibleMovesFrom(Coordinates::Coordinate c, std::vector<Move>& moves) {
		DoubleHexDirections helper;
		for (Coordinate dir : helper.directions) {
			getMovesInDirection(c, dir, moves);
		}
	}

	void Board::getFieldsWithSingleFish(std::vector<Move>& moves) {
		// Go through all fields of the board and adds set-moves on fields with 1 fish
		for (int x = 0; x < BOARD_SIZE_X; x++) {
			for (int y = 0; y < BOARD_SIZE_Y; y++) {
				if (board[x][y] == ONE_FISH) {
					Coordinate end(x, y, false);
					moves.push_back(Move(Coordinate(), end.toDoubleHex(), true));
				}
			}
		}
	}

	std::vector<Coordinate> Board::getPenguinPositions(bool team) {
		std::vector<Coordinate> positions;
		for (int x = 0; x < BOARD_SIZE_X; x++) {
			for (int y = 0; y < BOARD_SIZE_Y; y++) {
				if (board[x][y] == PLAYER_ONE + team) {
					positions.push_back(Coordinate(x, y, false));
				}
			}
		}

		return positions;
	}
}