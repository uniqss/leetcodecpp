#include "../inc.h"

// 这是一个 javascript 写法翻译过来的

class Solution {
    vector<vector<int>> ret;
    vector<int> curr;

   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrace(1, 0, k, n);
        return ret;
    }
    void backtrace(int idx, int sum, int k, int n) {
        if (sum >= n || idx > 9 || curr.size() >= k) {
            if (sum == n && curr.size() == k) ret.emplace_back(curr);
            return;
        }
        // 不选
        backtrace(idx + 1, sum, k, n);
        // 选
        curr.emplace_back(idx);
        sum += idx;
        backtrace(idx + 1, sum, k, n);
        sum -= idx;
        curr.pop_back();
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
