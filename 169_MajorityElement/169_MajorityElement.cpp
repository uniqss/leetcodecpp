#include "../inc.h"

class Solution {
   public:
    int majorityElement(vector<int>& nums) {}
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
