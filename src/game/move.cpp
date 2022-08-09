#include "move.h"

namespace Game {
    Move::Move() {}

    Move::Move(Coordinates::Coordinate mStart, Coordinates::Coordinate mDest) {
        start = mStart;
        destination = mDest;
    }
}