#include "../inc/inc.h"

class Solution {
   public:
    bool canJump(vector<int>& nums) {}
};

void test(vector<int>&& nums, bool expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.canJump(nums);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2}, true);
    test({2, 3, 1, 1, 4}, true);
    test({3, 2, 1, 0, 4}, false);
    return 0;
}
