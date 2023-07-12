#include "../inc.h"

class Solution {
   public:
    long long maxAlternatingSum(vector<int>& nums) {}
};

void test(vector<int>&& nums, long long expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.maxAlternatingSum(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({4, 2, 5, 3}, 7);
    test({5, 6, 7, 8}, 8);
    test({6, 2, 1, 2, 4, 5}, 10);
    return 0;
}
