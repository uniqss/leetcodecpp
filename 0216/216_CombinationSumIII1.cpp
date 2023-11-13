#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> curr;
        unordered_set<int> remain = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        dfs(ret, curr, remain, 0, k, n);
        return ret;
    }
    void dfs(vector<vector<int>>& ret, vector<int>& curr, unordered_set<int>& remain, int sum, int k, int n) {
        if (sum > n) return;
        if (curr.size() == k) {
            if (sum == n) ret.emplace_back(curr);
            return;
        }
        auto curr_remain = remain;
        for (int i : curr_remain) {
            if (!curr.empty() && i < *curr.rbegin()) continue;
            curr.emplace_back(i);
            remain.erase(i);
            dfs(ret, curr, remain, sum + i, k, n);
            remain.insert(i);
            curr.pop_back();
        }
    }
};

void test(int k, int n, vector<vector<int>>&& expect) {
    sortvvrawInnerAndOuter(expect);
    Solution so;
    auto ret = so.combinationSum3(k, n);
    sortvvrawInnerAndOuter(ret);
    assert_eq_ret(expect, ret);
    print(k);
    print(n);
}

int main() {
    test(3, 7, {{1, 2, 4}});
    test(3, 9, {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}});
    test(4, 1, {});
    return 0;
}
