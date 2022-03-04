#include "../inc.h"

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
    }
};

void test(vector<int>&& nums, int target, const vector<int>& expect) {
    Solution so;
    auto ret = so.twoSum(nums, target);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("#not ok.");
        pvraw(nums);
        praw(target);
        pvraw(expect);
        pvraw(ret);
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
