#include "../inc.h"

// 相对而言，个人还是更喜欢函数式的，不喜欢lambda
class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> dict = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::function<void(int, int, int)> bt = [&](int idx, int imin, int sum) {
            if (idx == k) {
                if (sum == n) ret.emplace_back(vector<int>(dict.begin(), dict.begin() + k));
                return;
            }
            if (sum > n) return;
            for (int i = max(idx, imin); i < 9; ++i) {
                swap(dict[idx], dict[i]);
                bt(idx + 1, i + 1, sum + dict[idx]);
                swap(dict[idx], dict[i]);
            }
        };
        bt(0, 0, 0);
        return ret;
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
