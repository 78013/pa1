#include <bits/stdc++.h>
#include "MyBoard.h"
#include "MyNode.h"

//// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
void printCurrentTime() {
    time_t now = time(nullptr);
    struct tm tStructure{};
    char buf[80];
    tStructure = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tStructure);
    std::cout << buf << std::endl;
}

int main() {
    printCurrentTime();
    MyNode initialNode;
    std::vector<std::vector<int> > goal = std::vector<std::vector<int> >(MyBoard::length,
                                                                         std::vector<int>(MyBoard::width));
    goal = {{1, 2, 3},
            {8, 0, 4},
            {7, 6, 5}};
    std::cout << "my initial f cost is " << initialNode.getFCost() << std::endl;
    initialNode.myBoard.current = {{1, 3, 4},
                                   {8, 6, 2},
                                   {7, 5, 0}};
    std::cout << "my initial f cost is " << initialNode.getFCost() << std::endl;
    initialNode.myBoard.printBoard(goal);
    if (!initialNode.myBoard.isCurrentGoal(goal)) {
        initialNode.myBoard.printBoard(initialNode.myBoard.current);
        std::cout << initialNode.myBoard.getHOutOfPlace(goal) << std::endl;
    }
    std::pair<int, int> x = initialNode.myBoard.getBlankTilePosition();
    std::cout << "The value of p2 is "
              << "(" << x.first << ", " << x.second << ")"
              << std::endl;
    if (initialNode.myBoard.canMoveDown(initialNode.myBoard.getBlankTilePosition())) {
        std::cout << "this should  not happen with the current code" << std::endl;
    } else { std::cout << "LGTM: looks good to me" << std::endl; }
    printCurrentTime();
}
