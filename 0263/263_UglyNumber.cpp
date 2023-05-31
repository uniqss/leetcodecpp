#include "../inc.h"

class Solution {
   public:
    bool isUgly(int n) {
        if (n <= 0) return false;
    }
};

void test(int n, bool expect) {
    Solution so;
    auto ret = so.isUgly(n);
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
    test(920408890, true);
    test(18, true);
    test(17, false);
    test(6, true);
    test(1, true);
    test(14, false);
    test(7, false);
    test(9, true);
    return 0;
}
