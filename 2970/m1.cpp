#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()

class Solution {
   public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i > 0 && j < n - 1 && nums[i - 1] >= nums[j + 1]) continue;
                bool valid = true;
                if (i == 0 && j == n - 1) {
                    ++ret;
                    continue;
                }
                if (i > 0) {
                    for (int l = 1; l < i; ++l) {
                        if (nums[l - 1] >= nums[l]) {
                            valid = false;
                            break;
                        }
                    }
                }
                if (!valid) continue;
                if (j < n - 1) {
                    for (int r = n - 2; r > j; --r) {
                        if (nums[r + 1] <= nums[r]) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;
                }
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
    test({1, 2, 3, 4}, 10);
    test({6, 5, 7, 8}, 7);
    test({8, 7, 6, 6}, 3);
    return 0;
}
