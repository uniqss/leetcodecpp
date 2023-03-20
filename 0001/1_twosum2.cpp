#include "../inc/inc.h"

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
    Solution so;
    auto ret = so.twoSum(nums, target);
    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());
    if (ret == expect) {
        print("ok");
    } else {
        print("#not ok.");
        print(nums);
        print(target);
        print(expect);
        print(ret);
    }
}

int main() {
    Solution s;
    vector<int> vi;
    int target = 0;
    vector<int> result;

    test({2, 7, 11, 15}, 9, {0, 1});
    test({3, 2, 4}, 6, {1, 2});
    test({3, 3}, 6, {0, 1});

    return 0;
}
