#include "../inc.h"

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {}
};

void test(vector<int>&& nums1, vector<int>&& nums2, const vector<int>& expect) {
    save4print(nums1, nums2);
    assert_eq_ret(expect, Solution().nextGreaterElement(nums1, nums2));
}

int main() {
    test({4, 1, 2}, {1, 3, 4, 2}, {-1, 3, -1});
    test({2, 4}, {1, 2, 3, 4}, {3, -1});
    return 0;
}
