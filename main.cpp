#include <bits/stdc++.h>
#include "MyBoard.h"

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
    MyBoard myBoard;
    std::vector<std::vector<int> > goal = std::vector<std::vector<int> >(MyBoard::length,
                                                                         std::vector<int>(MyBoard::width));
    goal = {{1, 2, 3},
            {8, 0, 4},
            {7, 6, 5}};
    myBoard.current = {{1, 3, 4},
                       {8, 6, 2},
                       {7, 5, 0}};
    myBoard.printBoard(goal);
    if (!myBoard.isCurrentGoal(goal)) {
        myBoard.printBoard(myBoard.current);
        std::cout << myBoard.getHOutOfPlace(goal) << std::endl;
    }
    std::pair<int, int> x = myBoard.getBlankTilePosition();
    std::cout << "The value of p2 is "
              << "(" << x.first << ", " << x.second << ")"
              << std::endl;
    if (myBoard.canMoveDown(myBoard.getBlankTilePosition())) {
        std::cout << "this should  not happen with the current code" << std::endl;
    } else { std::cout << "looks good to me" << std::endl; }
    printCurrentTime();
}
