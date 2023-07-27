#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> dict1(nums1.begin(), nums1.end()), dict2(nums2.begin(), nums2.end());
        vector<vector<int>> ret(2);
        for (auto d1 : dict1) {
            if (dict2.count(d1) == 0) ret[0].push_back(d1);
        }
        for (auto d2 : dict2) {
            if (dict1.count(d2) == 0) ret[1].push_back(d2);
        }

        return ret;
    }
};

void test(vector<int>&& nums1, vector<int>&& nums2, vector<vector<int>> expect) {
    auto nums1_param = nums1, nums2_param = nums2;
    Solution so;
    auto ret = so.findDifference(nums1, nums2);
    for (auto& v : expect) {
        sort(v.begin(), v.end());
    }
    for (auto& r : ret) {
        sort(r.begin(), r.end());
    }

    assert_eq_ret(expect, ret);
    print(nums1_param);
    print(nums2_param);
}

int main() {
    test({1, 2, 3}, {2, 4, 6}, {{1, 3}, {4, 6}});
    test({1, 2, 3, 3}, {1, 1, 2, 2}, {{3}, {}});
    return 0;
}
