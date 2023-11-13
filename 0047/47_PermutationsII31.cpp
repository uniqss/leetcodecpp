#include "../inc.h"

// 就是中文官方解法，只不过写法稍微优化了一下
class Solution {
    vector<bool> vis;

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        int len = nums.size();
        std::sort(nums.begin(), nums.end());
        vis.resize(len);
        vector<int> data;
        dfs(ret, len, nums, data);
        return ret;
    }
    void dfs(vector<vector<int>>& ret, int len, const vector<int>& nums, vector<int>& data) {
        if (data.size() == len) {
            ret.emplace_back(data);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (vis[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
            data.emplace_back(nums[i]);
            vis[i] = true;
            dfs(ret, len, nums, data);

            data.pop_back();
            vis[i] = false;
        }
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
