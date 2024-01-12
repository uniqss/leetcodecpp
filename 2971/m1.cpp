#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()

class Solution {
   public:
    long long largestPerimeter(vector<int>& nums) {
        long long ret = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int selcount = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (sum > nums[i] && i >= 2) {
                ret = max(ret, sum + nums[i]);
            }
            sum += nums[i];
        }
        return ret == 0 ? -1 : ret;
    }
};

void test(vector<int>&& nums, long long expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().largestPerimeter(nums));
}

int main() {
    test({1,      1,       2,       4,       8,        16,       32,       64,        128,
          256,    512,     1024,    2048,    4096,     8192,     16384,    32768,     131072,
          262144, 1048576, 4194304, 8388608, 16777216, 33554432, 67108864, 268435456, 536870912},
         -1);
    test({5, 5, 5}, 15);
    test({1, 12, 1, 2, 5, 50, 3}, 12);
    test({5, 5, 50}, -1);
    return 0;
}
