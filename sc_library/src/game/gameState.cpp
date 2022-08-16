#include "gameState.h"

namespace Game
{
    GameState::GameState() {}

    GameState::GameState(GameState& other) {
        this->board = Board(other.get_board());
        this->current_team = other.current_team;
        this->turn = other.get_turn();
        this->fish_count[0] = other.get_fishes_one();
        this->fish_count[1] = other.get_fishes_two();
        this->set_penguins[0] = other.get_penguins_one();
        this->set_penguins[1] = other.get_penguins_two();
    }

    std::vector<Move> GameState::get_possible_moves(bool team) {
        std::vector<Move> moves;
        if (set_penguins[team] != 4) {
            board.get_fields_with_single_fish(moves);
            return moves;
        }


        std::vector<Coordinate> penguins = board.get_penguin_positions(team);
        for (Coordinate c : penguins) {
            board.get_possible_moves_from(c, moves);
        }
        return moves;
    }

    std::vector<Move> GameState::get_possible_moves() {
        return get_possible_moves(current_team);
    }

    void GameState::perform_move(Move move) {
        if (move.is_set_move) {
            fish_count[current_team] += 1;
            board.set_field(move.destination, 4 + current_team);
            set_penguins[current_team]--;
        } else {
            fish_count[current_team] += board.get_field(move.destination);
            board.set_field(move.start, 0);
            board.set_field(move.destination, 4 + current_team);
        }
        turn++;
        current_team = !current_team;
    }

    bool GameState::immovable(bool team) {
        return get_possible_moves(team).empty();
    }

    bool GameState::is_over() {
        return immovable(0) && immovable(1);
    }

    //// BEWARE, GETTERS AND SETTERS AHEAD ////

    void GameState::set_turn(int newTurn) {
        this->turn = newTurn;
    }

    int GameState::get_turn() {
        return this->turn;
    }

    void GameState::set_board(Board newBoard) {
        this->board = newBoard;
    }

    Board GameState::get_board() {
        return this->board;
    }

    void GameState::set_fishes_one(int count) {
        this->fish_count[0] = count;
    }

    int GameState::get_fishes_one() {
        return this->fish_count[0];
    }

    void GameState::set_fishes_two(int count) {
        this->fish_count[1] = count;
    }

    int GameState::get_fishes_two() {
        return this->fish_count[1];
    }

    void GameState::set_penguins_one(int count) {
        this->set_penguins[0] = count;
    }

    int GameState::get_penguins_one() {
        return this->set_penguins[0];
    }

    void GameState::set_penguins_two(int count) {
        this->set_penguins[1] = count;
    }

    int GameState::get_penguins_two() {
        return this->set_penguins[1];
    }

} // namespace Game
