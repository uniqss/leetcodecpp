#include "../inc.h"

class Solution {
   public:
    string convertToTitle(int columnNumber) {}
};

void test(int columnNumber, string expect) {
    Solution so;
    auto ret = so.convertToTitle(columnNumber);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(columnNumber);
        print(expect);
        print(ret);
    }
}

int main() {
    test(1, "A");
    test(28, "AB");
    test(701, "ZY");
    return 0;
}
