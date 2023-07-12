#include "../inc.h"

class Solution {
   public:
    int alternateDigitSum(int n) {
        int ret = 0;
        int positive = 1;
        while (n > 0) {
            ret += (n % 10) * positive;
            n /= 10;
            positive *= -1;
        }
        ret *= -positive;

        return ret;
    }
};

void test(int n, int expect) {
    Solution so;
    auto ret = so.alternateDigitSum(n);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(n);
        print(expect);
        print(ret);
    }
}

int main() {
    test(521, 4);
    test(111, 1);
    test(886996, 0);
    return 0;
}
