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
        int begin = 0, sum = 0, windowSize = 0;
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            while (sum >= target) {
                windowSize = end - begin + 1;
                ret = min(ret, windowSize);
                sum -= nums[begin++];
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
        praw("ok");
    } else {
        praw("not ok");
        praw(target);
        pvraw(nums);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test(7, {2, 3, 1, 2, 4, 3}, 2);
    test(4, {1, 4, 4}, 1);
    test(11, {1, 1, 1, 1, 1, 1, 1, 1}, 0);
    return 0;
}
