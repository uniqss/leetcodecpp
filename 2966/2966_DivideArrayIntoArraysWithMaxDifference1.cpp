#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size() / 3;
        vector<vector<int>> ret(n);
        for (int i = 0; i < n; ++i) {
            int n1 = nums[i * 3], n2 = nums[i * 3 + 1], n3 = nums[i * 3 + 2];
            if (n3 - n1 > k) return {};
            ret[i].emplace_back(n1);
            ret[i].emplace_back(n2);
            ret[i].emplace_back(n3);
        }
        return ret;
    }
};

void test(vector<int>&& nums, int k, const vector<vector<int>>& expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().divideArray(nums, k));
}

int main() {
    test({1, 3, 4, 8, 7, 9, 3, 5, 1}, 2, {{1, 1, 3}, {3, 4, 5}, {7, 8, 9}});
    test({1, 3, 3, 2, 7, 3}, 3, {});
    return 0;
}
