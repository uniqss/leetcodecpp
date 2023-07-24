#include "../inc.h"

class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {}
};

void test(string&& str1, string&& str2, const string& expect) {
    Solution so;
    auto ret = so.gcdOfStrings(str1, str2);
    assert_eq_ret(expect, ret);
    print(str1);
    print(str2);
}

int main() {
    test("ABCABC", "ABC", "ABC");
    test("ABABAB", "ABAB", "AB");
    test("LEET", "CODE", "");
    return 0;
}
