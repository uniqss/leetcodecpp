#include "../inc.h"

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.longestSubarray(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums_param);
        print(expect);
        print(ret);
    }
}

int main() {
    test({1, 1, 0, 0, 1, 1, 1, 0, 1}, 4);
    test({1, 1, 0, 1}, 3);
    test({0, 1, 1, 1, 0, 1, 1, 0, 1}, 5);
    test({1, 1, 1}, 2);
    return 0;
}
