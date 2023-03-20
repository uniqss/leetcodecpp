#include "../inc/inc.h"

/*
brute force
nearly timeout. 872ms cost.
*/

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ret = INT_MAX;
        for (size_t begin = 0; begin < nums.size(); ++begin) {
            int sum = 0;
            for (size_t end = begin; end < nums.size(); ++end) {
                sum += nums[end];
                if (sum >= target) {
                    ret = min(ret, (int)(end - begin + 1));
                    break;
                }
            }
        }

        if (ret == INT_MAX) ret = 0;
        return ret;
    }
};

void test(int target, vector<int>&& nums, int expect) {
    Solution so;
    auto ret = so.minSubArrayLen(target, nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(target);
        print(nums);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test(7, {2, 3, 1, 2, 4, 3}, 2);
    test(4, {1, 4, 4}, 1);
    test(11, {1, 1, 1, 1, 1, 1, 1, 1}, 0);
    return 0;
}
