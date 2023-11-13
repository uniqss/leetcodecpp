#include "../inc.h"

/*
看起来更精炼的backtrack  这里借鉴了46题permutation的官方题解思路 https://leetcode.cn/problems/permutations/solutions/218275/quan-pai-lie-by-leetcode-solution-2/
这种思路简记：每次backtrack的时候，锁定一个坑位，挨个循环可选剩下的所有，填入当前坑位。再递归backtrack下一坑位。再还原
    这种思路看透了事情的本质，却能用最接近人的思维的方式还原整个过程，可谓聪明！
*/
class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        unordered_set<int> xyadd, xysub;
        vector<int> ys(n);
        for (int i = 0; i < n; ++i) ys[i] = i;
        helper(ys, 0, n, ret, xyadd, xysub);
        return ret;
    }
    void helper(vector<int>& ys, int begin, int end, vector<vector<string>>& ret, unordered_set<int>& xyadd,
                unordered_set<int>& xysub) {
        int n = ys.size();
        if (begin == end) {
            vector<string> curr(n, string(n, '.'));
            for (int x = 0; x < n; ++x) {
                int y = ys[x];
                curr[x][y] = 'Q';
            }
            ret.emplace_back(curr);
            return;
        }
        for (int x = begin; x < end; ++x) {
            int y = ys[x];
            // 容易翻车的点，这里是begin不是x
            int add = begin + y;
            int sub = begin - y;
            if (xyadd.count(add) != 0) continue;
            if (xysub.count(sub) != 0) continue;
            swap(ys[x], ys[begin]);
            xyadd.insert(add), xysub.insert(sub);
            helper(ys, begin + 1, end, ret, xyadd, xysub);
            xyadd.erase(add), xysub.erase(sub);
            swap(ys[x], ys[begin]);
        }
    }
};

void test(int n, vector<vector<string>>&& expect) {
    save4print(n);
    auto ret = Solution().solveNQueens(n);
    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test(4, {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}});
    test(1, {{"Q"}});
    return 0;
}
