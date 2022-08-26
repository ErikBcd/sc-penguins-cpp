from SC_PY_WRAPPER import Logic, GameState

class MyLogic(Logic):
    def get_move(self, gamestate):
        moves = gamestate.get_possible_moves()
        return moves[0]