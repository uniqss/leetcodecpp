#include "../inc.h"

class Solution {
   public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        vector<vector<int>> presum(n + 1, vector<int>(51));
        for (int i = 0; i < n; ++i) {
            presum[i + 1] = presum[i];
            ++presum[i + 1][nums[i]];
        }
        for (int i = 0; i < n; ++i) {
            int sum = 0, l, r;
            for (int j = 1; j <= 50; ++j) {
                l = presum[i + 1][j] > 0 ? 1 : 0;
                r = (presum[n][j] - presum[i+1][j]) > 0 ? 1 : 0;
                sum += l - r;
            }
            ret[i] = sum;
        }
        return ret;
    }
};

void test(vector<int>&& nums, const vector<int>& expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().distinctDifferenceArray(nums));
}
int main() {
    test({1, 2, 3, 4, 5}, {-3, -1, 1, 3, 5});
    test({3, 2, 3, 4, 2}, {-2, -1, 0, 2, 3});
    return 0;
}