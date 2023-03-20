#include "../inc/inc.h"

class Solution {
   public:
    bool isValid(string s) {}
};

void test(const string& s, bool expected) {
    Solution so;
    bool ret = so.isValid(s);
    if (expected != ret) {
        print("!!!!!!! not ok");
        print(s);
        print(expected);
        print(ret);
        print();
    } else {
        print("ok");
    }
}

int main() {
    test("()", true);
    test("()[]{}", true);
    test("(]", false);
    return 0;
}
