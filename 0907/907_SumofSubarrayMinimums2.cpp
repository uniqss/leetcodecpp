#include "../inc.h"

/*
O(n^2)会超时间限制
*/
class Solution {
   public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int64_t ret = 0, mod = 1e9 + 7;
        int dpij = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (j == i) {
                    dpij = arr[i];
                } else {
                    dpij = min(dpij, arr[j]);
                }
                ret += dpij;
                ret %= mod;
            }
        }
        return (int)ret;
    }
};

void test(vector<int>&& arr, int expect) {
    save4print(arr);
    assert_eq_ret(expect, Solution().sumSubarrayMins(arr));
}

int main() {
    test({3, 1, 2, 4}, 17);
    test({11, 81, 94, 43, 3}, 444);
    return 0;
}
