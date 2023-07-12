#include "../inc.h"

class Solution {
   public:
    int unequalTriplets(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    Solution so;
    auto ret = so.unequalTriplets(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums);
        print(expect);
        print(ret);
    }
}

int main() {
    test({4, 4, 2, 4, 3}, 3);
    test({1, 1, 1, 1, 1}, 0);
    return 0;
}
