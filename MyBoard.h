//
// Created by panda on 9/30/17.
//

#ifndef PA1_BOARD_H
#define PA1_BOARD_H

#include <iostream>
#include <vector>

class MyBoard {
public:
    const static int LENGTH = 3;
    const static int WIDTH = 3;
    std::vector<std::vector<int> > goal;
    std::vector<std::vector<int> > current;
    std::pair<int, int> blankTilePosition;

    MyBoard() {
        goal = std::vector<std::vector<int>>(LENGTH, std::vector<int>(WIDTH));
        current = std::vector<std::vector<int>>(LENGTH, std::vector<int>(WIDTH));;
    }

    void printBoard(std::vector<std::vector<int> > board) {
        for (int row = 0; row < LENGTH; row++) {
            for (int column = 0; column < WIDTH; column++) {
                std::cout << board[row][column];
            }
            std::cout << std::endl;
        }
    }

    bool isCurrentGoal() {
        for (int row = 0; row < LENGTH; row++) {
            for (int column = 0; column < WIDTH; column++) {
                if (current[row][column] != goal[row][column]) {
                    return false;
                }
            }
        }
        return true;
    }

    int getHOutOfPlace() {
        int hOutOfPlace = 0;
        for (int row = 0; row < LENGTH; row++) {
            for (int column = 0; column < WIDTH; column++) {
                if (current[row][column] != goal[row][column]) {
                    hOutOfPlace++;
                }
            }
        }
        if (hOutOfPlace > LENGTH * WIDTH) {
            throw std::invalid_argument("The number of tiles out of place cannot exceed the number of tiles.");
        }
        // we do not count the blank tile, 0, as being out of place.
        // this should not affect our calculation.
        return hOutOfPlace - 1;
    }

    bool canMoveRight(std::pair<int, int> blankTile) {
        return blankTile.first < LENGTH - 1;
    }

    bool canMoveDown(std::pair<int, int> blankTile) {
        return blankTile.second < WIDTH - 1;
    }

    bool canMoveLeft(std::pair<int, int> blankTile) {
        return blankTile.first > 0;
    }

    bool canMoveUp(std::pair<int, int> blankTile) {
        return blankTile.second > 0;
    }

    std::pair<int, int> getBlankTilePosition() {
        for (int row = 0; row < LENGTH; row++) {
            for (int column = 0; column < WIDTH; column++) {
                if (current[row][column] == 0) {
                    blankTilePosition.first = row;
                    blankTilePosition.second = column;
                    return blankTilePosition;
                }
            }
        }
    }
};

#endif //PA1_BOARD_H
