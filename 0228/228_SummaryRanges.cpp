#include "../inc.h"

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {}
};

void test(vector<int>&& nums, const vector<string>& expect) {
    save4print(nums);
    Solution so;
    auto ret = so.summaryRanges(nums);
    assert_eq_ret(expect, ret);
}

int main() {
    test({0, 1, 2, 4, 5, 7}, {"0->2", "4->5", "7"});
    test({0, 2, 3, 4, 6, 8, 9}, {"0", "2->4", "6", "8->9"});

    return 0;
}
