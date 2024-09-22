#include "../inc.h"

class Solution {
   public:
    vector<int> getConcatenation(vector<int>& nums) {}
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
