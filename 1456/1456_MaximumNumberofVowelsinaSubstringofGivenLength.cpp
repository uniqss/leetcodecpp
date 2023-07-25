#include "../inc.h"

class Solution {
   public:
    int maxVowels(string s, int k) {}
};

void test(string s, int k, int expect) {
    Solution so;
    auto ret = so.maxVowels(s, k);
    assert_eq_ret(expect, ret);
    print(s);
    print(k);
}

int main() {
    test("abciiidef", 3, 3);
    test("aeiou", 2, 2);
    test("leetcode", 3, 2);

    return 0;
}
