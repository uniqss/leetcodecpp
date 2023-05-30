#include "../inc.h"

class Solution {
   public:
    int mySqrt(int x) {}
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
