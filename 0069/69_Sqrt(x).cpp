#include "../inc.h"

class Solution {
   public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int64_t l = 1, r = x / 2, mid, mid2, ret = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            mid2 = mid * mid;
            if (mid2 == x) return mid;
            if (mid2 > x) {
                r = mid - 1;
            } else {
                ret = max(ret, mid);
                l = mid + 1;
            }
        }
        return ret;
    }
};

void test(int x, int expect) {
    save4print(x);
    assert_eq_ret(expect, Solution().mySqrt(x));
}

int main() {
    test(1, 1);
    test(2, 1);
    test(3, 1);
    test(4, 2);
    test(5, 2);
    test(8, 2);
    test(9, 3);
    test(2147395599, 46339);
    return 0;
}
