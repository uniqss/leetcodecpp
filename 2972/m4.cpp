#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()


class Solution {
   public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), l = 0;
        while (l < n - 1 && nums[l] < nums[l + 1]) ++l;
        if (l == n - 1) return n * (n + 1) / 2;
        long long ans = l + 2;
        for (int r = n - 1; r == n - 1 || nums[r] < nums[r + 1];--r) {
            while (l >= 0 && nums[l] >= nums[r]) --l;
            ans += l + 2;
        }

        return ans;
    }
};


void test(vector<int>&& nums, long long expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().incremovableSubarrayCount(nums));
}

int main() {
    test({27, 39, 32, 30, 38, 41, 28, 26, 49, 49}, 6);
    test({1, 2, 3, 4}, 10);
    test({6, 5, 7, 8}, 7);
    test({8, 7, 6, 6}, 3);
    return 0;
}
