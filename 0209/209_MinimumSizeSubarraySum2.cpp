#include "../inc.h"

/*
滑动窗口：
    窗口内的元素是什么？
    如何移动起始位置？
    如何移动终止位置？
*/

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ret = INT_MAX;
        int begin = 0, end = 0, sum = 0, size = nums.size(), windowsize = 0;
        while (end < size) {
            while (sum < target && end < size) {
                sum += nums[end++];
                ++windowsize;
            }
            if (sum < target) break;
            while (sum >= target) {
                ret = min(ret, windowsize);
                sum -= nums[begin++];
                --windowsize;
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
