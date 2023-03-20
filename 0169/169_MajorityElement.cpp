#include "../inc/inc.h"

class Solution {
   public:
    int majorityElement(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expected) {
    Solution so;
    auto ret = so.majorityElement(nums);
    if (ret == expected) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums);
        print(expected);
        print(ret);
    }
}

int main() {
    test({3, 2, 3}, 3);
    test({2, 2, 1, 1, 1, 2, 2}, 2);
    return 0;
}
