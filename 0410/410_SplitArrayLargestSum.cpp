#include "../inc.h"

/*
O(n^2k)
时间复杂度：O(nlogn)
空间复杂度：O(1)
*/
class Solution {
   public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 1e9, mid;
        auto valid = [&](int sum) {
            int currsum = 0, count = 1;
            for (int i = 0; i < n; ++i) {
                if (nums[i] > sum) return false;
                currsum += nums[i];
                if (currsum > sum) {
                    if (++count > k) return false;
                    currsum = nums[i];
                }
            }
            return true;
        };
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (valid(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};

void test(vector<int>&& nums, int k, int expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().splitArray(nums, k));
}

int main() {
    test({0}, 1, 0);
    test({10, 2, 3}, 2, 10);
    test({1, 4, 4}, 3, 4);
    test({7, 2, 5, 10, 8}, 2, 18);
    test({1, 2, 3, 4, 5}, 2, 9);
    return 0;
}