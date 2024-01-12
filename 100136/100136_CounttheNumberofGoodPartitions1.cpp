#include "../inc.h"

class Solution {
   public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> n2start;
        deque<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            if (n2start.count(nums[i]) == 0) {
                q.emplace_back(i, i);
                n2start[nums[i]] = i;
            } else {
                int start = n2start[nums[i]];
                while (q.back().first > start) {
                    q.pop_back();
                }
                q.back().second = i;
            }
        }
        int elementcount = q.size();
        int64_t k = elementcount - 1, mod = 1e9 + 7;
        if (k == 0) return 1;
        // return C(k,0) + C(k, 1) + C(k, 2) + ... + C(k, k);
        // = 2^k
        int64_t ret = 2;
        for (int i = 2; i <= k; ++i) {
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