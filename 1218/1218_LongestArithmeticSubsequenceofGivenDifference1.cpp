#include "../inc.h"

class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
        // mpp[x] = maximum length of arithmetic subsequence with given diff
        unordered_map<int,int> dp;
        int maxi = 0;
        for(int x : nums){
            dp[x] = dp[x-d] + 1;
            maxi = max(maxi, dp[x]);
        }
        return maxi;
    }
};

void test(vector<int>&& arr, int difference, int expect) {
    auto arr_param = arr;
    Solution so;
    auto ret = so.longestSubsequence(arr, difference);
    assert_eq_ret(expect, ret);
    print(arr_param);
    print(difference);
}

int main() {
    test({1, 2, 3, 4}, 1, 4);
    test({1, 3, 5, 7}, 1, 1);
    test({1, 5, 7, 8, 5, 3, 4, 2, 1}, -2, 4);
    return 0;
}
