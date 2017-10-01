//
// Created by panda on 9/30/17.
//

#ifndef PA1_MYNODE_H
#define PA1_MYNODE_H


#include "MyBoard.h"

class MyNode {
public:
    MyNode() {
        gCost = 0;
    }
    MyBoard myBoard;

    int getFCost() {
        return myBoard.getHOutOfPlace(myBoard.current);
    }

    int getGCost() {
        return gCost;
    }

    void setGCost(int input) {
        gCost = input;
    }

private:
    int gCost;
};


#endif //PA1_MYNODE_H
