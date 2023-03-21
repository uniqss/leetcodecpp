#include "../inc.h"

class Solution {
   public:
    bool isFlipedString(string s1, string s2) {}
};

void test(string&& s1, string&& s2, bool expect) {
    Solution so;
    auto ret = so.isFlipedString(s1, s2);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(s1);
        print(s2);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("", "", true);
    test("waterbottle", "erbottlewat", true);
    test("aa", "aba", false);
    return 0;
}
