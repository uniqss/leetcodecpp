#include "../inc.h"

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {}
};

void test(vector<int>&& nums, const vector<int>& expect) {
    vector<int> pnums = nums;
    Solution so;
    auto ret = so.removeDuplicates(nums);
    nums.resize(ret);
    if (nums == expect && ret == (int)expect.size()) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(pnums);
        pvraw(expect);
        pvraw(nums);
        praw(ret);
        pnewline();
    }
}

int main() {
    test({1, 1, 2}, {1, 2});
    test({0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 1, 2, 3, 4});

    return 0;
}
