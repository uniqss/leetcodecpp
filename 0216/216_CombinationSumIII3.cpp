#include "../inc.h"

// 这是另一个体系的办法
// 先把数堆满，记录当前位，记录当前位的最小可选位，把当前位和最小可选位之后全一一换，再回溯下一个位。完了再换回来
// 这种办法和人的思维是非常接近的 这个题目非常有意思
class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> dict = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        bt(ret, dict, 0, 0, k, n, 0);
        return ret;
    }
    void bt(vector<vector<int>>& ret, vector<int>& dict, int idx, int imin, int k, int n, int sum) {
        if (idx == k) {
            if (sum == n) ret.emplace_back(vector<int>(dict.begin(), dict.begin() + k));
            return;
        }
        if (sum > n) return;
        for (int i = max(idx, imin); i < 9; ++i) {
            swap(dict[idx], dict[i]);
            bt(ret, dict, idx + 1, i + 1, k, n, sum + dict[idx]);
            swap(dict[idx], dict[i]);
        }
    }
};

void test(int k, int n, vector<vector<int>>&& expect) {
    save4print(k, n);
    sortvvrawInnerAndOuter(expect);
    auto ret = Solution().combinationSum3(k, n);
    sortvvrawInnerAndOuter(ret);
    assert_eq_ret(expect, ret);
}

int main() {
    test(3, 7, {{1, 2, 4}});
    test(3, 9, {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}});
    test(4, 1, {});
    return 0;
}
