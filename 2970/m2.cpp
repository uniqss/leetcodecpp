#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()

class Solution {
   public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), l = 0;
        while (l < n - 1 && nums[l] < nums[l + 1]) ++l;
        if (l == n - 1) return n * (n + 1) / 2;
        int ret = l + 2;
        for (int r = n - 1; r == n - 1 || nums[r] < nums[r + 1]; --r) {
            while (l >= 0 && nums[l] >= nums[r]) --l;
            ret += l + 2;
        }

        return ret;
    }
};


void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().incremovableSubarrayCount(nums));
}

int main() {
    test({1, 2, 3, 4}, 10);
    test({6, 5, 7, 8}, 7);
    test({8, 7, 6, 6}, 3);
    return 0;
}
