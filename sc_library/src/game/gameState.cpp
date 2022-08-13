#include "gameState.h"

namespace Game
{
    GameState::GameState() {}

    GameState::GameState(GameState& other) {
        this->board = Board(other.getBoard());
        this->currentTeam = other.currentTeam;
        this->turn = other.getTurn();
        this->fishCount[0] = other.getFishesOne();
        this->fishCount[1] = other.getFishesTwo();
        this->setPenguins[0] = other.getUnsetPenguinsOne();
        this->setPenguins[1] = other.getUnsetPenguinsTwo();
    }

    std::vector<Move> GameState::getPossibleMoves(bool team) {
        std::vector<Move> moves;
        if (setPenguins[team] != 4) {
            board.getFieldsWithSingleFish(moves);
            return moves;
        }


        std::vector<Coordinate> penguins = board.getPenguinPositions(team);
        for (Coordinate c : penguins) {
            board.getPossibleMovesFrom(c, moves);
        }
        return moves;
    }

    std::vector<Move> GameState::getPossibleMoves() {
        return getPossibleMoves(currentTeam);
    }

    void GameState::performMove(Move move) {
        if (move.is_set_move) {
            fishCount[currentTeam] += 1;
            board.setField(move.destination, 4 + currentTeam);
            setPenguins[currentTeam]--;
        } else {
            fishCount[currentTeam] += board.getField(move.destination);
            board.setField(move.start, 0);
            board.setField(move.destination, 4 + currentTeam);
        }
        turn++;
        currentTeam = !currentTeam;
    }

    bool GameState::immovable(bool team) {
        return getPossibleMoves(team).empty();
    }

    bool GameState::isOver() {
        return immovable(0) && immovable(1);
    }

    //// BEWARE, GETTERS AND SETTERS AHEAD ////

    void GameState::setTurn(int newTurn) {
        this->turn = newTurn;
    }

    int GameState::getTurn() {
        return this->turn;
    }

    void GameState::setBoard(Board newBoard) {
        this->board = newBoard;
    }

    Board GameState::getBoard() {
        return this->board;
    }

    void GameState::setFishesOne(int count) {
        this->fishCount[0] = count;
    }

    int GameState::getFishesOne() {
        return this->fishCount[0];
    }

    void GameState::setFishesTwo(int count) {
        this->fishCount[1] = count;
    }

    int GameState::getFishesTwo() {
        return this->fishCount[1];
    }

    void GameState::setUnsetPenguinsOne(int count) {
        this->setPenguins[0] = count;
    }

    int GameState::getUnsetPenguinsOne() {
        return this->setPenguins[0];
    }

    void GameState::setUnsetPenguinsTwo(int count) {
        this->setPenguins[1] = count;
    }

    int GameState::getUnsetPenguinsTwo() {
        return this->setPenguins[1];
    }

} // namespace Game
