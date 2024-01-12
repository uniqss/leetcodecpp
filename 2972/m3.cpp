#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()


class Solution {
   public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        long long ret = 0;
        int inc = 0, dec = n - 1;
        while (inc < n - 1 && nums[inc + 1] > nums[inc]) ++inc;
        if (inc == n - 1) return n * (n + 1) / 2;
        while (dec > 0 && nums[dec - 1] < nums[dec]) --dec;
        for (int r = dec - 1; r < n; ++r) {
            int l = inc + 1;
            if (r < n - 1) {
                while (l > 0 && nums[r + 1] <= nums[l - 1]) --l;
            }
            ret += l + 1;
        }
        return ret;
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
