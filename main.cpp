#include <iostream>

bool check_solution(int goal[3][3], int initial[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (goal[i][j] == initial[i][j]) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int goal[3][3] = {{1, 2, 3},
                      {8, 0, 4},
                      {7, 6, 5}};
    int easy[3][3] = {{1, 3, 4},
                      {8, 6, 2},
                      {7, 0, 5}};
    int solved[3][3] = {{1, 2, 3},
                        {8, 0, 4},
                        {7, 6, 5}};
    std::cout << "The following line should say they match" << std::endl;
    if (check_solution(goal, solved)) {
        std::cout << "They match!" << std::endl;
    } else {
        std::cout << "They do not match!" << std::endl;
    }
    std::cout << "The following line should say they do not match" << std::endl;
    if (check_solution(goal, easy)) {
        std::cout << "They match!" << std::endl;
    } else {
        std::cout << "They do not match!" << std::endl;
    }
    return 0;
}
