#include "../inc.h"

// 官方题解，比我的苗条了一个数量级，性感多了
class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i < m && i < k; ++i) q.emplace(i, 0);
        vector<vector<int>> ret;
        while (k-- > 0 && !q.empty()) {
            auto [x, y] = q.top();
            q.pop();
            ret.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n) q.emplace(x, y + 1);
        }
        return ret;
    }
};

void test(vector<int>&& nums1, vector<int>&& nums2, int k, const vector<vector<int>>& expect) {
    save4print(nums1, nums2, k);
    assert_eq_ret(expect, Solution().kSmallestPairs(nums1, nums2, k));
}

int main() {
    test({1, 1, 2}, {1, 2, 3}, 10, {{1, 1}, {1, 1}, {2, 1}, {1, 2}, {1, 2}, {2, 2}, {1, 3}, {1, 3}, {2, 3}});
    test({1, 7, 11}, {2, 4, 6}, 3, {{1, 2}, {1, 4}, {1, 6}});
    test({1, 1, 2}, {1, 2, 3}, 2, {{1, 1}, {1, 1}});
    test({1, 2}, {3}, 3, {{1, 3}, {2, 3}});
    return 0;
}
