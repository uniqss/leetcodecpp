#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()


class Solution {
   public:
    long long incremovableSubarrayCount(vector<int>& nums) {}
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
