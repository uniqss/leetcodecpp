#include "../inc.h"

class Solution {
   public:
    int averageValue(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    Solution so;
    auto ret = so.averageValue(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(nums);
        print(expect);
        print(ret);
    }
}

int main() {
    test({1, 3, 6, 10, 12, 15}, 9);
    test({1, 2, 4, 7, 10}, 0);
    return 0;
}
