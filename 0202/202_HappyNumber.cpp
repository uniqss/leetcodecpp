#include "../inc.h"

class Solution {
   public:
    bool isHappy(int n) {}
};

void test(int n, bool expect) {
    Solution so;
    auto ret = so.isHappy(n);
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
    test(19, true);
    test(2, false);
    return 0;
}
