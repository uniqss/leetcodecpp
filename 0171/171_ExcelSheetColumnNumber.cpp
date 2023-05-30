#include "../inc.h"

class Solution {
   public:
    int titleToNumber(string columnTitle) {}
};

void test(string&& columnTitle, int expect) {
    Solution so;
    auto ret = so.titleToNumber(columnTitle);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(columnTitle);
        print(expect);
        print(ret);
    }
}

int main() {
    test("A", 1);
    test("AB", 28);
    test("ZY", 701);
    return 0;
}
