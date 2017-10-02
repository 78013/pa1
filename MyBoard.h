//
// Created by panda on 9/30/17.
//

#ifndef PA1_BOARD_H
#define PA1_BOARD_H

#include <iostream>
#include <vector>
#include "Direction.h"
#include "TilePosition.h"

class MyBoard {
public:
    const static int length = 3;
    const static int width = 3;
    std::vector<std::vector<int>> current;

    MyBoard() {
        current = std::vector<std::vector<int>>(length, std::vector<int>(width));
    }

    void printBoard(std::vector<std::vector<int>> board) {
        for (int row = 0; row < length; row++) {
            for (int column = 0; column < width; column++) {
                std::cout << board[row][column];
            }
            std::cout << std::endl;
        }
    }

    bool isSolved(std::vector<std::vector<int>> goal) {
        for (int row = 0; row < length; row++) {
            for (int column = 0; column < width; column++) {
                if (current[row][column] != goal[row][column]) {
                    return false;
                }
            }
        }
        return true;
    }

    int getHOutOfPlace(std::vector<std::vector<int>> goal) {
        int hOutOfPlace = 0;
        for (int row = 0; row < length; row++) {
            for (int column = 0; column < width; column++) {
                if (current[row][column] != goal[row][column]) {
                    hOutOfPlace++;
                }
            }
        }
        if (hOutOfPlace > length * width) {
            throw std::invalid_argument("The number of tiles out of place cannot exceed the number of tiles.");
        }
        // we do not count the blank tile, 0, as being out of place.
        // this should not affect our calculation.
        return hOutOfPlace - 1;
    }

    TilePosition getBlankTilePosition() {
        for (int row = 0; row < length; row++) {
            for (int column = 0; column < width; column++) {
                if (current[row][column] == 0) {
                    return TilePosition(row, column);
                }
            }
        }
    }

    TilePosition shiftTile(TilePosition blankTilePosition, Direction direction) {
        switch (direction) {
            case Direction::left:
                return TilePosition(blankTilePosition.row, blankTilePosition.column - 1);
//                return std::make_pair(blankTilePosition.row, blankTilePosition.column - 1);
            case Direction::right:
                return TilePosition(blankTilePosition.row, blankTilePosition.column + 1);
//                return std::make_pair(blankTilePosition.row, blankTilePosition.column + 1);
            case Direction::up:
                return TilePosition(blankTilePosition.row - 1, blankTilePosition.column);
//                return std::make_pair(blankTilePosition.row - 1, blankTilePosition.column);
            case Direction::down:
                return TilePosition(blankTilePosition.row + 1, blankTilePosition.column);
//                return std::make_pair(blankTilePosition.row + 1, blankTilePosition.column);
        }
    }

    bool canMoveTo(TilePosition blankTile, Direction direction) {
        blankTile = shiftTile(blankTile, direction);
        return
                blankTile.row >= 0 &&
                blankTile.column >= 0 &&
                blankTile.row < length &&
                blankTile.column < width;
    }

    std::vector<std::vector<int>> moveTo(Direction direction) {
        TilePosition blankTilePosition = getBlankTilePosition();
        std::vector<std::vector<int> > movedBoard(length, std::vector<int>(width));
        movedBoard = current;
        if (canMoveTo(blankTilePosition, direction)) {
            auto targetPosition = shiftTile(getBlankTilePosition(), direction);
            std::swap(movedBoard[blankTilePosition.row][blankTilePosition.column],
                      movedBoard[targetPosition.row][targetPosition.column]);
        }
        return movedBoard;
    }
};

#endif //PA1_BOARD_H
