//
// Created by panda on 9/30/17.
//

#ifndef PA1_BOARD_H
#define PA1_BOARD_H

#include <iostream>
#include <vector>
#include "Direction.h"

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

    bool isCurrentGoal(std::vector<std::vector<int>> goal) {
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

    std::pair<int, int> getBlankTilePosition() {
        std::pair<int, int> blankTilePosition;
        for (int row = 0; row < length; row++) {
            for (int column = 0; column < width; column++) {
                if (current[row][column] == 0) {
                    blankTilePosition.first = row;
                    blankTilePosition.second = column;
                    return blankTilePosition;
                }
            }
        }
    }

    std::pair<int, int> shiftTile(std::pair<int, int> blankTilePosition, Direction direction) {
        std::pair<int, int> newTilePosition;
        switch (direction) {
            case Direction::left:
                newTilePosition.first = blankTilePosition.first;
                newTilePosition.second = blankTilePosition.second - 1;
                return newTilePosition;
//                return std::make_pair(blankTilePosition.first, blankTilePosition.second - 1);
            case Direction::right:
                newTilePosition.first = blankTilePosition.first;
                newTilePosition.second = blankTilePosition.second + 1;
                return newTilePosition;
//                return std::make_pair(blankTilePosition.first, blankTilePosition.second + 1);
            case Direction::up:
                newTilePosition.first = blankTilePosition.first - 1;
                newTilePosition.second = blankTilePosition.second;
                return newTilePosition;
//                return std::make_pair(blankTilePosition.first - 1, blankTilePosition.second);
            case Direction::down:
                newTilePosition.first = blankTilePosition.first + 1;
                newTilePosition.second = blankTilePosition.second;
                return newTilePosition;
//                return std::make_pair(blankTilePosition.first + 1, blankTilePosition.second);
        }
    }

    bool canMoveTo(std::pair<int, int> blankTile, Direction direction) {
        blankTile = shiftTile(blankTile, direction);
        return
                blankTile.first >= 0 &&
                blankTile.second >= 0 &&
                blankTile.first < length &&
                blankTile.second < width;
    }

    std::vector<std::vector<int>> moveTo(Direction direction) {
        std::pair<int, int> blankTilePosition = getBlankTilePosition();
        std::vector<std::vector<int> > movedBoard(length, std::vector<int>(width));
        if (canMoveTo(blankTilePosition, direction)) {
            auto targetPosition = shiftTile(getBlankTilePosition(), direction);
            std::swap(movedBoard[blankTilePosition.first][blankTilePosition.second],
                      current[targetPosition.first][targetPosition.second]);
        }
        return movedBoard;
    }
};

#endif //PA1_BOARD_H
