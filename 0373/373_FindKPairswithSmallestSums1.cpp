#include "../inc.h"

// 理论是对的，但是会超时
class Solution {
    struct PairSumCmp {
        bool operator()(const vector<int>& lhs, const vector<int>& rhs) const {
            return lhs[0] + lhs[1] < rhs[0] + rhs[1];
        }
    };

   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, PairSumCmp> q;
        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i < m && i < k; ++i) {
            for (int j = 0; j < n && j < k; ++j) {
                q.push({nums1[i], nums2[j]});
                if (q.size() > k) q.pop();
            }
        }
        vector<vector<int>> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top()), q.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

void test(vector<int>&& nums1, vector<int>&& nums2, int k, const vector<vector<int>>& expect) {
    save4print(nums1, nums2, k);
    assert_eq_ret(expect, Solution().kSmallestPairs(nums1, nums2, k));
}

int main() {
    test({1, 7, 11}, {2, 4, 6}, 3, {{1, 2}, {1, 4}, {1, 6}});
    test({1, 1, 2}, {1, 2, 3}, 2, {{1, 1}, {1, 1}});
    test({1, 2}, {3}, 3, {{1, 3}, {2, 3}});
    return 0;
}
