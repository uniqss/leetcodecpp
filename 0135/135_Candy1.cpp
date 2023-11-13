#include "../inc.h"

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ret = 0;
        vector<int> dict(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1] && dict[i] <= dict[i - 1]) dict[i] = dict[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && dict[i] <= dict[i + 1]) dict[i] = dict[i + 1] + 1;
        }

        for (int d : dict) ret += d;
        return ret;
    }
};

void test(vector<int>&& ratings, int expect) {
    save4print(ratings);
    assert_eq_ret(expect, Solution().candy(ratings));
}

int main() {
    test({1, 0, 2}, 5);
    test({1, 2, 2}, 4);
    return 0;
}
