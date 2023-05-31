#include "../inc.h"

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int sum = (0 + nums.size()) * (nums.size() + 1) / 2;
        for (int n : nums) {
            sum -= n;
        }
        return sum;
    }
};

void test(vector<int>&& nums, int expect) {
    Solution so;
    auto ret = so.missingNumber(nums);
    auto nums_bk = nums;
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums_bk);
        print(expect);
        print(ret);
    }
}

int main() {
    test({3, 0, 1}, 2);
    test({0, 1}, 2);
    test({9, 6, 4, 2, 3, 5, 7, 0, 1}, 8);
    return 0;
}
