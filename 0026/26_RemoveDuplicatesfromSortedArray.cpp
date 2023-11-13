#include "../inc.h"

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {}
};

void test(vector<int>&& nums, const vector<int>& expect) {
    save4print(nums);
    vector<int> pnums = nums;
    auto ret = Solution().removeDuplicates(nums);
    nums.resize(ret);
    assert_retnone(nums == expect && ret == (int)expect.size());
}

int main() {
    test({1, 1, 2}, {1, 2});
    test({0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 1, 2, 3, 4});

    return 0;
}
