#include "../inc.h"

/*
甚好，但不推荐。有一定的理解成本，可维护性低
*/
class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), pre = 1, ret = 1, inc = 1, dec = 0;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;
            } else {
                ++dec;
                if (dec == inc) ++dec;
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }
};

void test(vector<int>&& ratings, int expect) {
    save4print(ratings);
    assert_eq_ret(expect, Solution().candy(ratings));
}

int main() {
    test({1, 3, 2, 2, 1}, 7);
    test({1, 3, 4, 5, 2}, 11);
    test({1, 0, 2}, 5);
    test({1, 2, 2}, 4);
    return 0;
}
