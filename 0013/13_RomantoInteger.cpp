#include "../inc.h"

class Solution {
   public:
    int romanToInt(string s) {}
};

void test(string s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().romanToInt(s));
}

int main() {
    test("MCDLXXVI", 1476);
    test("III", 3);
    test("LVIII", 58);
    test("MCMXCIV", 1994);
    return 0;
}