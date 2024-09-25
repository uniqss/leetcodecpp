#include "../inc.h"

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        unordered_set<int> dict(nums.begin(), nums.end());
        for (int i = 1; i <= n; ++i)
            if (dict.count(i) == 0) ret.emplace_back(i);
        return ret;
    }
};

void test(vector<int>&& nums, vector<int>&& expect) {
    sort(expect.begin(), expect.end());
    auto ret = Solution().findDisappearedNumbers(nums);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({4, 3, 2, 7, 8, 2, 3, 1}, {5, 6});
    test({1, 1}, {2});
    return 0;
}
