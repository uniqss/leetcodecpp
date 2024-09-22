#include "../inc.h"

// hash
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mii;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = mii.find(target - nums[i]);
            if (it == mii.end()) {
                mii[nums[i]] = i;
            } else {
                return {i, it->second};
            }
        }
        return {-1, -1};
    }
};

void test(vector<int>&& nums, int target, vector<int>&& expect) {
    save4print(nums, target);
    auto ret = Solution().twoSum(nums, target);
    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({2, 7, 11, 15}, 9, {0, 1});
    test({3, 2, 4}, 6, {1, 2});
    test({3, 3}, 6, {0, 1});

    return 0;
}
