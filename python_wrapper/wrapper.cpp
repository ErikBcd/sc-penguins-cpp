#include <boost/python.hpp>
#include <vector>

#include "client.h"
#include "coordinates.h"
#include "board.h"
#include "gameState.h"
#include "move.h"
#include "logic.h"

using namespace boost::python;

/// Scaffoldings for wrapping

// gameState.h
std::vector<Game::Move> (Game::GameState::*possible_moves_1)() 
    = &Game::GameState::get_possible_moves;
std::vector<Game::Move> (Game::GameState::*possible_moves_2)(bool) 
    = &Game::GameState::get_possible_moves;

// logic.h
class LogicWrapper : public Logic::Logic, public wrapper<Logic::Logic> {
private:
    /* data */
public:
    Game::Move get_move(Game::GameState& gamestate) {
        if (override get_move = this->get_override("get_move")) {
            return get_move(gamestate);
        }
        return Logic::Logic::get_move(gamestate);
    }

    Game::Move default_get_move(Game::GameState& gamestate) {
        return this->Logic::Logic::get_move(gamestate);
    }
};



BOOST_PYTHON_MODULE(SC_PY_WRAPPER) {
    /// client.h
    class_<Client::Game_Client, boost::noncopyable>("Client", init<Logic::Logic&>())
        .def("Start", &Client::Game_Client::Start);

    class_<LogicWrapper, boost::noncopyable>("Logic")
        .def("get_move", &Logic::Logic::get_move, &LogicWrapper::default_get_move);

    /// coordinates.h
    
    class_<Coordinates::Coordinate>("Coordinate")
        .def(init<int, int, optional<bool>>())
        .def_readwrite("x", &Coordinates::Coordinate::x)
        .def_readwrite("y", &Coordinates::Coordinate::y)
        .def_readwrite("is_double_hex", &Coordinates::Coordinate::is_double_hex)
        .def("to_double_hex", &Coordinates::Coordinate::to_double_hex)
        .def("to_array_coordinate", &Coordinates::Coordinate::to_array_coordinate)
        .def(self + self);

    class_<Coordinates::DoubleHexDirections>("DoubleHexDirections")
        .def_readonly("LEFT", &Coordinates::DoubleHexDirections::LEFT)
        .def_readonly("RIGHT", &Coordinates::DoubleHexDirections::RIGHT)
        .def_readonly("UP_LEFT", &Coordinates::DoubleHexDirections::UP_LEFT)
        .def_readonly("UP_RIGHT", &Coordinates::DoubleHexDirections::UP_RIGHT)
        .def_readonly("DOWN_LEFT", &Coordinates::DoubleHexDirections::DOWN_LEFT)
        .def_readonly("DOWN_RIGHT", &Coordinates::DoubleHexDirections::DOWN_RIGHT)
        .def_readonly("directions", &Coordinates::DoubleHexDirections::directions);

    /// board.h
    class_<Game::Board, boost::noncopyable>("Board")
        .def(init<Game::Board&>())
        .def_readonly("EMPTY", &Game::Board::EMPTY)
        .def_readonly("ONE_FISH", &Game::Board::ONE_FISH)
        .def_readonly("TWO_FISHES", &Game::Board::TWO_FISHES)
        .def_readonly("THREE_FISHES", &Game::Board::THREE_FISHES)
        .def_readonly("PLAYER_ONE", &Game::Board::PLAYER_ONE)
        .def_readonly("PLAYER_TWO", &Game::Board::PLAYER_TWO)
//      .def_readwrite("board", &Game::Board::board)
        .def("coordinate_in_bounds", &Game::Board::coordinate_in_bounds)
        .def("get_field", &Game::Board::get_field)
        .def("set_field", &Game::Board::set_field)
        .def("get_possible_moves_from", &Game::Board::get_possible_moves_from)
        .def("get_fields_with_single_fish", &Game::Board::get_fields_with_single_fish)
        .def("get_penguin_positions", &Game::Board::get_penguin_positions)
        .def("to_string", &Game::Board::to_string);

    class_<Game::GameState, boost::noncopyable>("GameState")
        .def(init<Game::GameState&>())
        .def_readwrite("current_team", &Game::GameState::current_team)
        .def("get_possible_moves", possible_moves_1)
        .def("get_possible_moves", possible_moves_2)
        .def("perform_move", &Game::GameState::perform_move)
        .def("immovable", &Game::GameState::immovable)
        .def("is_over", &Game::GameState::is_over)
        .def("set_turn", &Game::GameState::set_turn)
        .def("get_turn", &Game::GameState::get_turn)
        .def("set_board", &Game::GameState::set_board)
        .def("get_board", &Game::GameState::get_board)
        .def("set_fishes_one", &Game::GameState::set_fishes_one)
        .def("get_fishes_one", &Game::GameState::get_fishes_one)
        .def("set_fishes_two", &Game::GameState::set_fishes_two)
        .def("get_fishes_two", &Game::GameState::get_fishes_two)
        .def("get_penguins_one", &Game::GameState::get_penguins_one)
        .def("set_penguins_one", &Game::GameState::set_penguins_one)
        .def("get_penguins_two", &Game::GameState::get_penguins_two)
        .def("set_penguins_two", &Game::GameState::set_penguins_two);
    
    class_<Game::Move>("Move")
        .def(init<Coordinates::Coordinate, Coordinates::Coordinate, optional<bool>>())
        .def_readwrite("start", &Game::Move::start)
        .def_readwrite("destination", &Game::Move::destination)
        .def_readwrite("is_set_move", &Game::Move::is_set_move);
}