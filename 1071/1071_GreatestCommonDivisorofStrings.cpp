#include "../inc.h"

class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {}
};

void test(string&& str1, string&& str2, const string& expect) {
    save4print(str1, str2);
    assert_eq_ret(expect, Solution().gcdOfStrings(str1, str2));
}

int main() {
    test("ABABABAB", "ABAB", "ABAB");
    test("ABCABC", "ABC", "ABC");
    test("ABABAB", "ABAB", "AB");
    test("LEET", "CODE", "");
    return 0;
}
