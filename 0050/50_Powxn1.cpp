#include "../inc.h"

class Solution {
   public:
    double myPow(double x, int n) {
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        if (n == 0) return 1;
        if (n < 0) {
            return myPow(1 / x, -n);
        }
        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        } else {
            return x * myPow(x, n - 1);
        }
    }
};

template <class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type almost_equal(T x, T y, int ulp) {
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::fabs(x - y) <= std::numeric_limits<T>::epsilon() * std::fabs(x + y) * ulp
           // unless the result is subnormal
           || std::fabs(x - y) < std::numeric_limits<T>::min();
}

void test(double x, int n, double expect) {
    Solution so;
    auto ret = so.myPow(x, n);
    if (almost_equal(ret, expect, 2)) {
        print("ok.");
    } else {
        print("not ok.");
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test(1.0, -2147483648, 1);
    test(2.0, 10, 1024.0);
    test(2.1, 3, 9.261);
    test(2.0, -2, 0.25);
    return 0;
}
