#include "board.h"

namespace Game {
	Board::Board() {}

	Board::Board(const Board& other) {
		for (int x = 0; x < BOARD_SIZE_X; x++) {
			for (int y = 0; y < BOARD_SIZE_Y; y++) {
				this->board[x][y] = other.board[x][y];
			}
		}
	}
	
	bool Board::coordinate_in_bounds(Coordinates::Coordinate c) {
		return (c.x >= 0 && c.y >= 0) && (c.x < BOARD_SIZE_X && c.y < BOARD_SIZE_Y);
	}

	char Board::get_field(Coordinates::Coordinate c) {
		if (c.is_double_hex) {
			Coordinates::Coordinate cd = c.to_array_coordinate();
			if (coordinate_in_bounds(cd)) {
				return board[cd.x][cd.y];
			} else {
				throw "Coordinate is out of bounds!";
			}
		}
		
		if (coordinate_in_bounds(c)) {
			return board[c.x][c.y];
		} else {
			throw "Coordinate is out of bounds!";
		}
	}

	void Board::set_field(Coordinates::Coordinate c, char field) {
		if (c.is_double_hex) {
			Coordinates::Coordinate cd = c.to_array_coordinate();
			if (coordinate_in_bounds(cd)) {
				board[cd.x][cd.y] = field;
				return;
			} else {
				throw "Coordinate is out of bounds!";
			}
		}

		if (coordinate_in_bounds(c)) {
			board[c.x][c.y] = field;
			return;
		} else {
			throw "Coordinate is out of bounds!";
		}
	}

	bool Board::is_valid_field(Coordinate c) {
		Coordinate arrCoord = (c.is_double_hex) ? c.to_array_coordinate() : c;

		if (c.is_double_hex) {
			if (c.x < 0 || c.y < 0 || c.x >= (BOARD_SIZE_X)*2 || c.y >= BOARD_SIZE_Y) {
				return false;
			}
		}

		if (!coordinate_in_bounds(arrCoord)) {
			return false;
		}

		return (board[arrCoord.x][arrCoord.y] != EMPTY) 
			&& (board[arrCoord.x][arrCoord.y] != PLAYER_ONE)
			&& (board[arrCoord.x][arrCoord.y] != PLAYER_TWO);
	}

	void Board::
		get_moves_in_direction(Coordinates::Coordinate start, Coordinates::Coordinate dir, std::vector<Move>& moves) {
		Coordinates::Coordinate c = start;
		c = dir + c;
		while (is_valid_field(c)) {
			moves.push_back(Move(start, c));
			c = dir + c;
		}
	}

	void Board::get_possible_moves_from(Coordinates::Coordinate c, std::vector<Move>& moves) {
		DoubleHexDirections helper;
		Coordinates::Coordinate doubleHex = (c.is_double_hex) ? c : c.to_double_hex();
		for (Coordinate dir : helper.directions) {
			get_moves_in_direction(doubleHex, dir, moves);
		}
	}

	void Board::get_fields_with_single_fish(std::vector<Move>& moves) {
		// Go through all fields of the board and adds set-moves on fields with 1 fish

		for (int x = 0; x < BOARD_SIZE_X; x++) {
			for (int y = 0; y < BOARD_SIZE_Y; y++) {
				if (board[x][y] == ONE_FISH) {
					Coordinate end(x, y, false);
					moves.push_back(Move(Coordinate(), end.to_double_hex(), true));
				}
			}
		}
	}

	std::vector<Coordinate> Board::get_penguin_positions(bool team) {
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

	std::string Board::to_string() {
		std::string s;
		for (size_t x = 0; x < BOARD_SIZE_X; x++) {
			for (size_t y = 0; y < BOARD_SIZE_Y; y++) {
				s += 48 + board[y][x];
			}
			s += '\n';
		}

		return s;
	}
}