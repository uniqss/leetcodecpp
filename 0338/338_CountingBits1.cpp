#include "../inc.h"

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);
        int v = 0, curr, count;
        for (int i = 0; i <= n; ++i) {
            curr = v++;
            count = 0;
            while (curr != 0) {
                if (curr % 2 == 1) ++count;
                curr >>= 1;
            }
            ret[i] = count;
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