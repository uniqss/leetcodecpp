#include "../inc.h"

class Solution {
   public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int cmax = 0, csize = candies.size();
        for (int candy : candies) cmax = max(cmax, candy);
        vector<bool> ret(csize);
        for (int i = 0; i < csize; ++i) {
            ret[i] = candies[i] + extraCandies >= cmax;
        }
        return ret;
    }
};

void test(vector<int>&& candies, int extraCandies, const vector<bool>& expect) {
    save4print(candies, extraCandies);
    assert_eq_ret(expect, Solution().kidsWithCandies(candies, extraCandies));
}

int main() {
    test({2, 3, 5, 1, 3}, 3, {true, true, true, false, true});
    test({4, 2, 1, 1, 2}, 1, {true, false, false, false, false});
    test({12, 1, 12}, 10, {true, false, true});
    return 0;
}
