#include "../inc.h"

/*
中文官方的解法
*/
class Solution {
    vector<int> t;
    vector<vector<int>> ret;

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ret;
    }
    void dfs(int curr, const vector<int>& nums) {
        if (curr == nums.size()) {
            ret.emplace_back(t);
            return;
        }
        t.push_back(nums[curr]);
        dfs(curr + 1, nums);
        t.pop_back();
        dfs(curr + 1, nums);
    }
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    save4print(nums);
    auto ret = Solution().subsets(nums);
    std::sort(ret.begin(), ret.end());
    std::sort(expect.begin(), expect.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 2, 3}, {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}});
    test({0}, {{}, {0}});
}
