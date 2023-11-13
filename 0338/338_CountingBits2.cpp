#include "../inc.h"

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int ones = 0, x = i;
            while (x > 0) {
                x &= (x - 1);
                ++ones;
            }
            ret[i] = ones;
        }
        return ret;
    }
};

void test(int n, vector<int>&& expect) {
    Solution so;
    auto ret = so.countBits(n);
    assert_eq_ret(expect, ret);
    print(n);
}

int main() {
    test(2, {0, 1, 1});
    test(5, {0, 1, 1, 2, 1, 2});
    return 0;
}