#include "../inc.h"

class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), vmax = 0;
        for (int v : nums) vmax = max(vmax, v);
        int start = -1, count = 0;
        long long ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == vmax) {
                if (start == -1) start = i;
                ++count;
                if (count > k) {
                    ++start;
                    while (nums[start] != vmax) ++start;
                }
            }
            // 这个是神来之笔，不需要判定是否相等，是尾巴任意一个新数来了，它就能构成一个新的start + 1个组合
            if (count >= k) ret += start + 1;
        }
        return ret;
    }
};

void test(vector<int>&& nums, int k, long long expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().countSubarrays(nums, k));
}

int main() {
    test({61, 23, 38, 23, 56, 40, 82, 56, 82, 82, 82, 70, 8, 69, 8, 7, 19, 14, 58, 42, 82, 10, 82, 78, 15, 82}, 2, 224);
    test({1, 3, 2, 3, 3}, 2, 6);
    test({1, 4, 2, 1}, 3, 0);
    return 0;
}
