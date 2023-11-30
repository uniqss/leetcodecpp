#include "../inc.h"

class Solution {
   public:
    int uniqueLetterString(string s) {}
};

void test(string s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().uniqueLetterString(s));
}

int main() {
    test("ABC", 10);
    test("ABA", 8);
    test("LEETCODE", 92);
    return 0;
}
