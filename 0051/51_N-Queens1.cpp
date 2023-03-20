#include "../inc.h"

/*
参考官方思路，hash方式比较灵活，用的内存也相对较少。在n确定且比较小的情况下，可以做一定的优化，参见11的实现

row1 (col_idx1)  (col_idx2)  (col_idx3)    ........................row
row2 (col_idx1)  (col_idx2)  (col_idx3)
    .
    .
    .
    .
    .
    .
    .
    .
    col

*/
class Solution {
    std::unordered_set<int> columns;
    std::unordered_set<int> leftdowns;
    std::unordered_set<int> leftups;

   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> col_idxes(n, -1);
        backtrace(ret, col_idxes, 0, n);
        return ret;
    }
    void backtrace(vector<vector<string>>& ret, vector<int>& col_idxes, int row, int n) {
        if (row == n) {
            constructBoard(ret, col_idxes, n);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (columns.find(col) != columns.end()) continue;
            int leftdown = row + col;
            int leftup = row - col;
            if (leftdowns.find(leftdown) != leftdowns.end()) continue;
            if (leftups.find(leftup) != leftups.end()) continue;
            columns.insert(col);
            leftdowns.insert(leftdown);
            leftups.insert(leftup);
            col_idxes[row] = col;
            backtrace(ret, col_idxes, row + 1, n);
            col_idxes[row] = -1;
            columns.erase(col);
            leftdowns.erase(leftdown);
            leftups.erase(leftup);
        }
    }
    void constructBoard(vector<vector<string>>& ret, const vector<int>& col_idxes, int n) {
        vector<string> board;
        for (int i = 0; i < n; ++i) {
            string curr(n, '.');
            curr[col_idxes[i]] = 'Q';
            board.emplace_back(curr);
        }
        ret.emplace_back(board);
    }
};

void test(int n, vector<vector<string>>&& expect) {
    Solution so;
    auto ret = so.solveNQueens(n);
    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());
    if (expect == ret) {
        print("ok.");
    } else {
        print("not ok.");
        print(n);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test(4, {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}});
    test(1, {{"Q"}});
    return 0;
}
