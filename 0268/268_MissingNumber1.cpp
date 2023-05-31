#include "../inc.h"

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) return i;
        }
        return nums.size();
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
