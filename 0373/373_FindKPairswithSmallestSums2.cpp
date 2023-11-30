#include "../inc.h"

// 居然是我测试用例抄过来抄错了，，，翻了一晚的车
class Solution {
    struct Nii {
        int i = 0;
        int j = 0;
        int sum;
        bool operator<(const Nii& rhs) const { return this->sum > rhs.sum; }
    };

   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> ret;
        priority_queue<Nii, vector<Nii>> q;
        for (int i = 0; i < m && i < k; ++i) q.push({i, 0, nums1[i] + nums2[0]});
        for (int64_t c = 0; c < k && c < (int64_t)m * n; ++c) {
            auto vtop = q.top();
            q.pop();
            ret.push_back({nums1[vtop.i], nums2[vtop.j]});
            if (vtop.j + 1 < n) q.push({vtop.i, vtop.j + 1, nums1[vtop.i] + nums2[vtop.j + 1]});
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
