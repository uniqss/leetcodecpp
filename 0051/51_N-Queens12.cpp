#include "../inc.h"

class Solution {
    std::unordered_set<int> columns;
    std::unordered_set<int> lefttops;
    std::unordered_set<int> leftdowns;

   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> col_idxes;
        backtrace(ret, col_idxes, 0, n);
        return ret;
    }
    void backtrace(vector<vector<string>>& ret, vector<int>& col_idxes, int row, int n) {
        if (row == n) {
            construct_board(ret, col_idxes, n);
            return;
        }
        for (int col_idx = 0; col_idx < n; ++col_idx) {
            if (columns.count(col_idx) > 0) continue;
            int lefttop = col_idx - row;
            if (lefttops.count(lefttop) > 0) continue;
            int leftdown = col_idx + row;
            if (leftdowns.count(leftdown) > 0) continue;
            columns.insert(col_idx);
            lefttops.insert(lefttop);
            leftdowns.insert(leftdown);
            col_idxes.push_back(col_idx);
            backtrace(ret, col_idxes, row + 1, n);
            col_idxes.pop_back();
            columns.erase(col_idx);
            lefttops.erase(lefttop);
            leftdowns.erase(leftdown);
        }
    }
    void construct_board(vector<vector<string>>& ret, vector<int>& col_idxes, int n) {
        vector<string> curr(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            curr[i][col_idxes[i]] = 'Q';
        }
        ret.emplace_back(curr);
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
