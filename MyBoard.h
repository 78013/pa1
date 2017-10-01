//
// Created by panda on 9/30/17.
//

#ifndef PA1_BOARD_H
#define PA1_BOARD_H

#include <iostream>
#include <vector>

class MyBoard {
public:
    const static int length = 3;
    const static int width = 3;
    std::vector<std::vector<int> > current;
    std::pair<int, int> blankTilePosition;

    MyBoard() {
        current = std::vector<std::vector<int> >(length, std::vector<int>(width));;
    }

    void printBoard(std::vector<std::vector<int> > board) {
        for (int row = 0; row < length; row++) {
            for (int column = 0; column < width; column++) {
                std::cout << board[row][column];
            }
            std::cout << std::endl;
        }
    }

    bool isCurrentGoal(std::vector<std::vector<int> > goal) {
        for (int row = 0; row < length; row++) {
            for (int column = 0; column < width; column++) {
                if (current[row][column] != goal[row][column]) {
                    return false;
                }
            }
        }
        return true;
    }

    int getHOutOfPlace(std::vector<std::vector<int> > goal) {
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

    bool canMoveRight(std::pair<int, int> blankTile) {
        return blankTile.second < width - 1;
    }

    bool canMoveDown(std::pair<int, int> blankTile) {
        return blankTile.first < length - 1;
    }

    bool canMoveLeft(std::pair<int, int> blankTile) {
        return blankTile.second > 0;
    }

    bool canMoveUp(std::pair<int, int> blankTile) {
        return blankTile.first > 0;
    }

    std::pair<int, int> getBlankTilePosition() {
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

    std::vector<std::vector<int> > moveUp() {
        blankTilePosition = getBlankTilePosition();
        std::vector<std::vector<int> > movedBoard = std::vector<std::vector<int> >(length, std::vector<int>(width));
        if (canMoveUp(blankTilePosition)) {
            std::swap(movedBoard[blankTilePosition.first][blankTilePosition.second],
                      current[blankTilePosition.first][blankTilePosition.second - 1]);
        }
        return movedBoard;
    }

    std::vector<std::vector<int> > moveDown() {
        blankTilePosition = getBlankTilePosition();
        std::vector<std::vector<int> > movedBoard = std::vector<std::vector<int> >(length, std::vector<int>(width));
        if (canMoveUp(blankTilePosition)) {
            std::swap(movedBoard[blankTilePosition.first][blankTilePosition.second],
                      current[blankTilePosition.first][blankTilePosition.second + 1]);
        }
        return movedBoard;
    }

    std::vector<std::vector<int> > moveLeft() {
        blankTilePosition = getBlankTilePosition();
        std::vector<std::vector<int> > movedBoard = std::vector<std::vector<int> >(length, std::vector<int>(width));
        if (canMoveUp(blankTilePosition)) {
            std::swap(movedBoard[blankTilePosition.first][blankTilePosition.second],
                      current[blankTilePosition.first - 1][blankTilePosition.second]);
        }
        return movedBoard;
    }

    std::vector<std::vector<int> > moveRight() {
        blankTilePosition = getBlankTilePosition();
        std::vector<std::vector<int> > movedBoard = std::vector<std::vector<int> >(length, std::vector<int>(width));
        if (canMoveUp(blankTilePosition)) {
            std::swap(movedBoard[blankTilePosition.first][blankTilePosition.second],
                      current[blankTilePosition.first + 1][blankTilePosition.second]);
        }
        return movedBoard;
    }
};

#endif //PA1_BOARD_H
