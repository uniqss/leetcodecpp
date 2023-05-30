#include "../inc.h"

class Solution {
   public:
    int singleNumber(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    Solution so;
    auto ret = so.singleNumber(nums);
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
    test({2, 2, 1}, 1);
    test({4, 1, 2, 1, 2}, 4);
    test({1}, 1);
    return 0;
}
