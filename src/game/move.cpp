#include "move.h"

namespace Game {
    Move::Move() {}

    Move::Move(Coordinates::Coordinate mStart, Coordinates::Coordinate mDest, bool set_move) {
        start = mStart;
        destination = mDest;

        is_set_move = set_move;
    }
}