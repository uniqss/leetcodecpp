#include "../inc.h"

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

void test(vector<int>&& nums, int k, const vector<int>& expect) {
    vector<int> pnums = nums;
    Solution so;
    so.rotate(nums, k);
    if (nums == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(pnums);
        praw(k);
        pvraw(expect);
        pvraw(nums);
        pnewline();
    }
}

int main() {
    test({1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4});
    test({-1, -100, 3, 99}, 2, {3, 99, -1, -100});

    return 0;
}
