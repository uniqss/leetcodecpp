#include "../inc.h"

// good good study, day day up
class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> curr;
        std::function<void(int, int)> bt = [&](int idx, int sum) {
            if (sum >= n || idx > 9 || curr.size() >= k) {
                if (sum == n && curr.size() == k) ret.emplace_back(curr);
                return;
            }
            // 不选
            bt(idx + 1, sum);
            // 选
            curr.emplace_back(idx);
            sum += idx;
            bt(idx + 1, sum);
            // 养成习惯，逆序还原，可以有效规避很多问题
            sum -= idx;
            curr.pop_back();
        };
        bt(1, 0);
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
