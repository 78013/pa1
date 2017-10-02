//
// Created by panda on 10/1/17.
//

#ifndef PA1_MYTREE_H
#define PA1_MYTREE_H


#include <utility>

#include "MyNode.h"

class MyTree {
public:
    explicit MyTree(MyNode inputRoot) {
        root = std::move(inputRoot);
    }

private:
    MyNode root;
};


#endif //PA1_MYTREE_H
