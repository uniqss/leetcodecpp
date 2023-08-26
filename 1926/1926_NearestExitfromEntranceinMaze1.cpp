#include "../inc.h"

class Solution {
   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        maze[entrance[0]][entrance[1]] = '+';
        for (int i = 0; i < m; ++i) {
            if (maze[i][0] == '.') maze[i][0] = 'o';
            if (maze[i][n - 1] == '.') maze[i][n - 1] = 'o';
        }
        for (int i = 0; i < n; ++i) {
            if (maze[0][i] == '.') maze[0][i] = 'o';
            if (maze[m - 1][i] == '.') maze[m - 1][i] = 'o';
        }
        queue<pair<int, int>> q;
        q.emplace(entrance[0], entrance[1]);
        unordered_set<int> visited;
        auto trans = [](int x, int y) { return x * 101 + y; };
        int level = 0;
        auto add_grid = [&q, &visited, &maze, &trans](int x, int y) {
            if ((maze[x][y] == '.' || maze[x][y] == 'o') && visited.count(trans(x, y)) == 0) {
                visited.insert(trans(x, y));
                q.emplace(x, y);
            }
        };
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                auto [x, y] = q.front();
                q.pop();
                if (maze[x][y] == 'o') {
                    return level;
                }
                if (x > 0) add_grid(x - 1, y);
                if (x < m - 1) add_grid(x + 1, y);
                if (y > 0) add_grid(x, y - 1);
                if (y < n - 1) add_grid(x, y + 1);
            }
            ++level;
        }

        return -1;
    }
};

void test(vector<vector<char>>&& maze, vector<int>&& entrance, int expect) {
    auto m_param = maze;
    auto e_param = entrance;
    Solution so;
    auto ret = so.nearestExit(maze, entrance);
    assert_eq_ret(expect, ret);
    print(m_param);
    print(e_param);
}

int main() {
    test({{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}}, {1, 2}, 1);
    test({{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}}, {1, 0}, 2);
    test({{'.', '+'}}, {0, 0}, -1);
    return 0;
}
