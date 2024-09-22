#include "../inc.h"

class Solution {
   public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ret(nums.size() * 2);
        int n = nums.size();
        for (int i = 0; i < n; ++i) ret[i] = ret[i + n] = nums[i];
        return ret;
    }
};

void test(vector<int>&& nums, const vector<int>& expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().getConcatenation(nums));
}

int main() {
    test({1, 2, 1}, {1, 2, 1, 1, 2, 1});
    test({1, 3, 2, 1}, {1, 3, 2, 1, 1, 3, 2, 1});
    return 0;
}
