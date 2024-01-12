#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()

class Solution {
   public:
    bool hasTrailingZeros(vector<int>& nums) {}
};

void test(vector<int>&& nums, bool expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().hasTrailingZeros(nums));
}

int main() {
    test({1, 2, 3, 4, 5}, true);
    test({2, 4, 8, 16}, true);
    test({1, 3, 5, 7, 9}, false);
    return 0;
}
