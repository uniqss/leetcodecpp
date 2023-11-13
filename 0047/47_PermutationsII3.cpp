#include "../inc.h"
/*
中文官方解法
*/
class Solution {
    vector<int> vis;

   public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int start, int len, vector<int>& perm) {
        if (start == len) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (vis[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, start + 1, len, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, nums.size(), perm);
        return ans;
    }
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    save4print(nums);
    auto ret = Solution().permuteUnique(nums);
    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 1, 2}, {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}});
    test({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    test({0, 1}, {{0, 1}, {1, 0}});
    test({1}, {{1}});
    return 0;
}
