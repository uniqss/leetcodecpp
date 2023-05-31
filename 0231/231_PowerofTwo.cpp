#include "../inc.h"

class Solution {
   public:
    bool isPowerOfTwo(int n) {}
};

void test(int n, bool expect) {
    Solution so;
    auto ret = so.isPowerOfTwo(n);
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
    test(1, true);
    test(16, true);
    test(3, false);
    return 0;
}
