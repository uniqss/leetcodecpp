#include "../inc.h"

class Solution {
   public:
    int numberOfGoodPartitions(vector<int>& nums) {}
};

void test(vector<int>&& nums, int epxect) {
    save4print(nums);
    assert_eq_ret(epxect, Solution().numberOfGoodPartitions(nums));
}

int main() {
    test({2, 3, 2, 8, 8}, 2);
    test({1, 5, 1, 5, 6}, 2);
    test({1, 2, 3, 4}, 8);
    test({1, 1, 1, 1}, 1);
    test({1, 2, 1, 3}, 2);
    return 0;
};