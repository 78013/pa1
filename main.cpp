#include <bits/stdc++.h>

std::map<std::vector<std::vector<int> >, bool> visited;
std::map<std::vector<std::vector<int> >, std::vector<std::vector<int> > > parent;
std::vector<std::vector<int> > goal(3, std::vector<int>(3));

bool visit(std::vector<std::vector<int> > a) {
    return visited[a] == true;
}

int manhattan(std::vector<std::vector<int> > a, int moves) {
    int dist = moves;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != 0) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (a[i][j] == goal[k][l])
                            dist += abs(i - k) + abs(j - l);
                    }
                }
            }
        }
    }

    return dist;
}

bool safe(int i, int j) {
    return i >= 0 && i <= 2 && j >= 0 && j <= 2;
}

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, +1};

std::vector<std::vector<std::vector<int> > > neighbours(std::vector<std::vector<int> > a) {
    std::pair<int, int> pos;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 0) {
                pos.first = i;
                pos.second = j;
                break;
            }
        }
    }
    std::vector<std::vector<std::vector<int> > > ans;
    for (int k = 0; k < 4; k++) {
        int cx = pos.first;
        int cy = pos.second;
        std::vector<std::vector<int> > n = a;
        if (safe(cx + dx[k], cy + dy[k])) {
            std::swap(n[cx + dx[k]][cy + dy[k]], n[cx][cy]);
            ans.push_back(n);
        }
    }

    return ans;
}

typedef std::pair<std::vector<std::vector<int> >, int> state;

struct cmp {
    bool operator()(state &a, state &b) {
        int am = manhattan(a.first, a.second);
        int bm = manhattan(b.first, b.second);
        return am < bm;
    }
};

void print_path(std::vector<std::vector<int> > s) {
    if (parent.count(s))
        print_path(parent[s]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", s[i][j]);
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return;
}

void print(std::vector<std::vector<int> > s) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", s[i][j]);
        }
        std::cout << std::endl;
    }
}

void solve(std::vector<std::vector<int> > a, int moves) {
    std::cout << "now we will begin to solve" << std::endl;
    std::priority_queue<state, std::vector<state>, cmp> Q;
    Q.push(state(a, moves));
    while (!Q.empty()) {
        std::vector<std::vector<int> > s = Q.top().first;
        Q.pop();

        visited[s] = true;
        print(s);
        if (s == goal) {
            printf("yeah\n");
            print_path(s);
            break;
        }
        std::vector<std::vector<std::vector<int> > > ns = neighbours(s);
        std::vector<std::vector<std::vector<int> > >::iterator it;
        printf("1..\n");
        for (it = ns.begin(); it != ns.end(); it++) {
            print(*it);
            std::cout << std::endl;
            std::vector<std::vector<int> > temp = *it;
            if (!visit(temp)) {
                parent.insert(std::pair<std::vector<std::vector<int> >, std::vector<std::vector<int> > >(temp, s));
                Q.push(state(temp, moves + 1));
            }
        }
    }
    return;
}

int main() {
    std::vector<std::vector<int> > a(3, std::vector<int>(3));
    //std::vector<std::vector<int> > goal(3,std::vector<int> (3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> a[i][j];
        }
    }
    std::cout << "Solution...\n\n";
    goal[0][0] = 1;
    goal[0][1] = 2;
    goal[0][2] = 3;
    goal[1][0] = 8;
    goal[1][1] = 0;
    goal[1][2] = 4;
    goal[2][0] = 7;
    goal[2][1] = 6;
    goal[2][2] = 5;

    solve(a, 0);
}