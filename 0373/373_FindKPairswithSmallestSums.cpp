#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {}
};

void test(vector<int>&& nums1, vector<int>&& nums2, int k, const vector<vector<int>>& expect) {
    save4print(nums1, nums2, k);
    assert_eq_ret(expect, Solution().kSmallestPairs(nums1, nums2, k));
}

int main() {
    test({1, 1, 2}, {1, 2, 3}, 10, {{1, 1}, {1, 1}, {2, 1}, {1, 2}, {1, 2}, {2, 2}, {1, 3}, {1, 3}, {2, 3}});
    test({1, 7, 11}, {2, 4, 6}, 3, {{1, 2}, {1, 4}, {1, 6}});
    test({1, 1, 2}, {1, 2, 3}, 2, {{1, 1}, {1, 1}});
    test({1, 2}, {3}, 3, {{1, 3}, {2, 3}});
    return 0;
}
