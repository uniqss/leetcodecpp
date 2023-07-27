#include "../inc.h"

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {
        int ret = 0;
        vector<int> count;
        int sum = 1, last = nums[0];
        nums.push_back(1 - nums[nums.size() - 1]);
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == last) {
                ++sum;
            } else {
                count.push_back(last > 0 ? sum : -sum);
                last = nums[i];
                sum = 1;
            }
        }
        for (int i = 0; i < count.size(); i++) {
            if (count[i] > 0) {
                ret = max(ret, count[i]);
            }
            if (i > 1 && count[i] > 0 && count[i - 1] == -1 && count[i - 2] > 0) {
                ret = max(ret, count[i] + count[i - 2]);
            }
        }

        if (ret == nums.size() - 1) --ret;

        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.longestSubarray(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums_param);
        print(expect);
        print(ret);
    }
}

int main() {
    test({1, 1, 0, 0, 1, 1, 1, 0, 1}, 4);
    test({1, 1, 0, 1}, 3);
    test({0, 1, 1, 1, 0, 1, 1, 0, 1}, 5);
    test({1, 1, 1}, 2);
    return 0;
}
