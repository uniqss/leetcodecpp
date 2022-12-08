#include "../inc.h"

/*
这里做了一定的优化，内存会多很多，但是性能明显比unordered体系快非常多，数组下标的性能比hash的性能在频繁增删的情况下是要高出很多的
*/
template <typename _Tp, std::size_t _Nm>
class SafeArray : public std::array<_Tp, _Nm> {
   public:
    const _Tp& operator[](int __n) const {
        if (__n < 0) {
            string err = "array index out of bound. __n:" + std::to_string(__n);
            throw std::logic_error(err);
        }
        return std::array<_Tp, _Nm>::operator[](__n);
    }

    _Tp& operator[](int __n) {
        if (__n < 0) {
            string err = "array index out of bound. __n:" + std::to_string(__n);
            throw std::logic_error(err);
        }
        return std::array<_Tp, _Nm>::operator[](__n);
    }
};

class Solution {
#define N_MAX 10
    SafeArray<bool, N_MAX> columns;
    SafeArray<bool, N_MAX * 2> leftdowns;
    SafeArray<bool, N_MAX * 2> leftups;

   public:
    vector<vector<string>> solveNQueens(int n) {
        // 这里其实可以更不讲武德一点直接 memset
        columns.fill(false);
        leftdowns.fill(false);
        leftups.fill(false);

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
            if (columns[col]) continue;
            int leftdown = row + col;
            int leftup = row - col + N_MAX;
            if (leftdowns[leftdown]) continue;
            if (leftups[leftup]) continue;
            columns[col] = true;
            leftdowns[leftdown] = true;
            leftups[leftup] = true;
            col_idxes[row] = col;
            backtrace(ret, col_idxes, row + 1, n);
            col_idxes[row] = -1;
            columns[col] = false;
            leftdowns[leftdown] = false;
            leftups[leftup] = false;
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
