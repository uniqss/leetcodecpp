#include "../inc.h"

class Solution {
   public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        unordered_map<int, int> n2start;
        for (int i = 0; i < n; ++i) {
            if (n2start.count(nums[i]) == 0) {
                stk.emplace(i);
                n2start[nums[i]] = i;
            } else {
                int start = n2start[nums[i]];
                while (stk.top() > start) stk.pop();
            }
        }
        int k = stk.size() - 1;
        int64_t ret = 1, mod = 1e9 + 7;
        for (int i = 1; i <= k; ++i) {
            ret = (ret * 2) % mod;
        }
        return ret;
    }
};

void test(vector<int>&& nums, int epxect) {
    save4print(nums);
    assert_eq_ret(epxect, Solution().numberOfGoodPartitions(nums));
}

int main() {
    test({2, 3, 2, 8, 8}, 2);
    test({1, 5, 1, 5, 6}, 2);
    test({1, 2, 3, 4}, 8);
    test({1, 1, 1, 1}, 1);
    test({1, 2, 1, 3}, 2);
    return 0;
};