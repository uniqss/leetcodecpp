#include "../inc.h"

// 这种题目，一定一定一定一定要画图，或者是在纸上，一定要非常清晰哪个是ｘ方向，哪个是ｙ方向
// 必须像熟悉自己的掌纹一样清晰地了解 每个变量所代表的意义！切记！
class Solution {
   public:
    int totalNQueens(int n) {
        vector<int> ys(n);
        for (int y = 0; y < n; ++y) ys[y] = y;
        int ret = 0;
        unordered_set<int> sum, sub;
        dfs(ys, 0, n, ret, sum, sub);
        return ret;
    }
    void dfs(vector<int>& ys, int xcurr, int xmax, int& ret, unordered_set<int>& sum, unordered_set<int>& sub) {
        if (xcurr == xmax) {
            ++ret;
            return;
        }
        for (int x = xcurr; x < xmax; ++x) {
            swap(ys[x], ys[xcurr]);
            if (sum.count(xcurr + ys[xcurr]) == 0 && sub.count(xcurr - ys[xcurr]) == 0) {
                sum.insert(xcurr + ys[xcurr]);
                sub.insert(xcurr - ys[xcurr]);
                dfs(ys, xcurr + 1, xmax, ret, sum, sub);
                sub.erase(xcurr - ys[xcurr]);
                sum.erase(xcurr + ys[xcurr]);
            }
            swap(ys[x], ys[xcurr]);
        }
    }
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().totalNQueens(n));
}

int main() {
    test(4, 2);
    return 0;
}
