#include "../inc.h"

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
    }
};

void test(vector<int>&& nums, vector<int>&& expect) {
    Solution so;
    vector<int> nums_saved = nums;

    so.nextPermutation(nums);
    if (nums == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(nums_saved);
        pvraw(expect);
        pvraw(nums);
    }
}

int main() {
    test({1, 2, 3}, {1, 3, 2});
    test({3, 2, 1}, {1, 2, 3});
    test({1, 1, 5}, {1, 5, 1});
    return 0;
}
