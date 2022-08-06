#pragma once

#include "util/coordinates.h"
#include "move.h"

#include <vector>

#define BOARD_SIZE_X 8
#define BOARD_SIZE_Y 8

#define EMPTY 0
#define ONE_FISH 1 
#define TWO_FISHES 2 
#define THREE_FISHES 3 
#define PLAYER_ONE 4
#define PLAYER_TWO 5

namespace Game {
	class Board {
	public:
		Board();
		char board[BOARD_SIZE_X][BOARD_SIZE_Y];
		char getField(Coordinates::Coordinate c);

		std::vector<Move> getPossibleMovesFrom(Coordinates::Coordinate c);
	};
}