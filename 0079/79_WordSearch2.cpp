#include "../inc.h"

// 这样就没什么难度了，dfs经典回溯
class Solution {
    int m = 0, n = 0;
    static inline const vector<pair<int, int>> nexts = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int x, int y, int idx, const string& word) {
        char ch = board[x][y];
        if (ch != word[idx]) return false;
        if (idx + 1 == word.size()) return true;
        board[x][y] = '#';
        for (auto [nx, ny] : nexts) {
            nx += x, ny += y;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || board[nx][ny] == '#') continue;
            if (dfs(board, nx, ny, idx + 1, word)) return true;
        }

        board[x][y] = ch;
        return false;
    }
};

void test(vector<vector<char>>&& board, const string& word, bool expect) {
    save4print(board, word);
    assert_eq_ret(expect, Solution().exist(board, word));
}

int main() {
    test({{'a'}}, "a", true);
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCCED", true);
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "SEE", true);
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCB", false);
    return 0;
}
