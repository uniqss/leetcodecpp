#include "../inc.h"

class Solution {
   public:
    bool repeatedSubstringPattern(string s) {}
};

void test(string&& s, bool expect) {
    Solution so;
    auto ret = so.repeatedSubstringPattern(s);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(s);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("abac", false);
    test("abab", true);
    test("abcabcabcabc", true);
    return 0;
}
