#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ret;
        vector<int> curr;
        dfs(candidates, 0, candidates.size(), target, curr, ret);
        return vector<vector<int>>(ret.begin(), ret.end());
    }
    void dfs(vector<int>& candidates, int idxcurr, int idxmax, int remain, vector<int>& curr, set<vector<int>>& ret) {
        if (remain == 0) ret.emplace(curr);
        if (remain <= 0) return;
        if (idxcurr >= idxmax) return;
        // 这里没有做这层剪枝，所以会穷举所有。要做这层剪枝要先排序，会大大缩减dfs树的大小，代价是值得的
        // if (candidates[idxcurr] > remain) return;
        curr.emplace_back(candidates[idxcurr]);
        dfs(candidates, idxcurr, idxmax, remain - candidates[idxcurr], curr, ret);
        curr.pop_back();
        dfs(candidates, idxcurr + 1, idxmax, remain, curr, ret);
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