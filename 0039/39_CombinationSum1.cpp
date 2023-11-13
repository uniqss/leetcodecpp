#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> curr;
        helper(candidates, curr, 0, ret, target);
        return ret;
    }
    void helper(const vector<int>& candidates, vector<int>& curr, int start, vector<vector<int>>& ret, int target) {
        if (target < 0) return;
        if (target == 0) {
            ret.emplace_back(curr);
            return;
        }
        if (start >= candidates.size()) return;
        if (candidates[start] > target) return;
        curr.emplace_back(candidates[start]);
        helper(candidates, curr, start, ret, target - candidates[start]);
        curr.pop_back();
        helper(candidates, curr, start + 1, ret, target);
    }
};

void test(vector<int>&& candidates, int target, const vector<vector<int>>& expect) {
    save4print(candidates, target);
    assert_eq_ret(expect, Solution().combinationSum(candidates, target));
}

int main() {
    test({2, 3, 6, 7}, 7, {{2, 2, 3}, {7}});
    test({2, 3, 5}, 8, {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}});
    test({2}, 1, {});
    return 0;
}