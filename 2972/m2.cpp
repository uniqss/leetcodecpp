#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()


class Solution {
   public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        int inc = 0, dec = n - 1;
        while (inc < n - 1 && nums[inc + 1] > nums[inc]) ++inc;
        if (inc == n - 1) return n * (n + 1) / 2;
        while (dec > 0 && nums[dec - 1] < nums[dec]) --dec;
        for (int i = 0; i <= inc + 1; ++i) {
            for (int j = dec - 1; j < n; ++j) {
                if (i > 0 && j < n - 1 && nums[i - 1] >= nums[j + 1]) continue;
                ++ret;
            }
        }
        return ret;
    }
};


void test(vector<int>&& nums, int expect) {
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
