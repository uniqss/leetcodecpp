#include "../inc/inc.h"

class Solution {
   public:
    int jump(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.jump(nums);
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
    test({2, 3, 1, 1, 4}, 2);
    test({2, 3, 0, 1, 4}, 2);
    return 0;
}
