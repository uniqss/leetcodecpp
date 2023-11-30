#include "../inc.h"

class Solution {
   public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (x == 1.0) return 1.0;
        int64_t validn = n;
        if (x == -1.0) return validn % 2 == 0 ? 1.0 : -1.0;
        if (n < 0) validn *= -1;
        unordered_map<int, double> dp;
        if (n < 0) return helper(1 / x, validn, dp);
        return helper(x, validn, dp);
    }
    double helper(double x, int64_t n, unordered_map<int, double>& dp) {
        if (dp.count(n) == 0) {
            if (n == 1)
                dp[n] = x;
            else {
                double dl = helper(x, n / 2, dp);
                double dr = helper(x, n - n / 2, dp);
                dp[n] = dl * dr;
            }
        }
        return dp[n];
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
    save4print(x, n);
    assert_eq_ret(expect, Solution().myPow(x, n));
}

int main() {
    test(-1.0, -2147483648, 1);
    test(1.0, -2147483648, 1);
    test(2.0, 10, 1024.0);
    test(2.1, 3, 9.261);
    test(2.0, -2, 0.25);
    return 0;
}
