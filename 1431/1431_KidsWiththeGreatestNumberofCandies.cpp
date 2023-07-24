#include "../inc.h"

class Solution {
   public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {}
};

void test(vector<int>&& candies, int extraCandies, const vector<bool>& expect) {
    auto candies_param = candies;
    Solution so;
    auto ret = so.kidsWithCandies(candies, extraCandies);
    assert_eq_ret(expect, ret);
    print(candies_param);
    print(extraCandies);
}

int main() {
    test({2, 3, 5, 1, 3}, 3, {true, true, true, false, true});
    test({4, 2, 1, 1, 2}, 1, {true, false, false, false, false});
    test({12, 1, 12}, 10, {true, false, true});
    return 0;
}
