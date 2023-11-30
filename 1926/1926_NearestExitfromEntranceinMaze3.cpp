#include "../inc.h"

class Solution {
   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        for (int i = 0; i < m; ++i) {
            if (maze[i][0] == '.') maze[i][0] = 'o';
            if (maze[i][n - 1] == '.') maze[i][n - 1] = 'o';
        }
        for (int j = 0; j < n; ++j) {
            if (maze[0][j] == '.') maze[0][j] = 'o';
            if (maze[m - 1][j] == '.') maze[m - 1][j] = 'o';
        }
        maze[entrance[0]][entrance[1]] = 'e';
        queue<pair<int, int>> q;
        q.emplace(entrance[0], entrance[1]);
        int depth = -1;
        while (!q.empty()) {
            int qsize = q.size();
            ++depth;
            for (int i = 0; i < qsize; ++i) {
                auto [x, y] = q.front();
                q.pop();
                // 项目中更推荐这种把check放在里面取出来一次性的做法，否则要写四次check
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (maze[x][y] == '+') continue;
                if (maze[x][y] == '.' || maze[x][y] == 'e') maze[x][y] = '+';
                if (maze[x][y] == 'o') return depth;
                q.emplace(x - 1, y);
                q.emplace(x + 1, y);
                q.emplace(x, y - 1);
                q.emplace(x, y + 1);
            }
        }
        return -1;
    }
};

void test(vector<vector<char>>&& maze, vector<int>&& entrance, int expect) {
    save4print(maze, entrance);
    assert_eq_ret(expect, Solution().nearestExit(maze, entrance));
}

int main() {
    test({{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}}, {1, 2}, 1);
    test({{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}}, {1, 0}, 2);
    test({{'.', '+'}}, {0, 0}, -1);
    return 0;
}
