#include "../inc.h"

class Solution {
   public:
    int minFlips(int a, int b, int c) {
        int ret = 0;
        for (int i = 1; i < 31; ++i) {
            if (c % 2 == 0) {
                if (a % 2 != 0) ++ret;
                if (b % 2 != 0) ++ret;
            } else {
                if ((a % 2 == 0) && (b % 2 == 0)) ++ret;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
            if (a + b + c == 0) break;
        }
        return ret;
    }
};

void test(int a, int b, int c, int expect) {
    Solution so;
    auto ret = so.minFlips(a, b, c);
    assert_eq_ret(expect, ret);
    print(a);
    print(b);
    print(c);
}

int main() {
    test(2, 6, 5, 3);
    test(4, 2, 7, 1);
    test(1, 2, 3, 0);
    return 0;
}