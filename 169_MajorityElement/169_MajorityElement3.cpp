#include "../inc.h"

/*
这个也略有取巧，就是排序后，最中间的一定是出现最多的(这里出现最多是大于[n/2]向下取整的)
n奇,最中间的一定是
 [2, 3, 3] 中间的3
n偶，左半最后一个一定是
 [2, 3, 4, 4] 这种是不满足的，一定是
 [2, 4, 4, 4] 这种，就是要过半，要大于 [n/2] 向下取整  不是大于等于
*/
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

void test(vector<int>&& nums, int expected) {
    Solution so;
    auto ret = so.majorityElement(nums);
    if (ret == expected) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(nums);
        praw(expected);
        praw(ret);
    }
}

int main() {
    test({3, 2, 3}, 3);
    test({2, 2, 1, 1, 1, 2, 2}, 2);
    return 0;
}
