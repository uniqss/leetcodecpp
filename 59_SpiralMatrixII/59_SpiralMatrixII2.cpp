#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int loop = n / 2, count = 0, xymin = 0, xymax = n - 1, x, y;
        while (loop-- > 0) {
            x = xymin;
            y = xymin;

            for (; y < xymax; ++y) ret[x][y] = ++count;
            for (; x < xymax; ++x) ret[x][y] = ++count;
            for (; y > xymin; --y) ret[x][y] = ++count;
            for (; x > xymin; --x) ret[x][y] = ++count;

            ++xymin;
            --xymax;
        }

        if (n % 2 == 1) {
            ret[n / 2][n / 2] = ++count;
        }

        return ret;
    }
};

void test(int n, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.generateMatrix(n);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("not ok.");
        praw(n);
        pvvraw(expect);
        pvvraw(ret);
        pnewline();
    }
}

int main() {
    test(4, {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}});
    test(3, {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}});
    test(1, {{1}});
    return 0;
}
