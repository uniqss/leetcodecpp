#include "../inc.h"

class Solution {
   public:
    int mySqrt(int x) {
        int l = 0, r = x, mid = 0;
        int64_t mid2 = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            mid2 = (int64_t)mid * mid;
            if (mid2 == x)
                return mid;
            else if (mid2 < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};

void test(int x, int expect) {
    Solution so;
    auto ret = so.mySqrt(x);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(x);
        print(expect);
        print(ret);
    }
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
