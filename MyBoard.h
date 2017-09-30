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

    MyBoard() {
        goal = std::vector<std::vector<int>>(LENGTH, std::vector<int>(WIDTH));
        current = std::vector<std::vector<int>>(LENGTH, std::vector<int>(WIDTH));;
    }

    void printGoalBoard() {
        for (int row = 0; row < LENGTH; row++) {
            for (int column = 0; column < WIDTH; column++) {
                std::cout << goal[row][column];
            }
            std::cout << std::endl;
        }
    }
};

#endif //PA1_BOARD_H
