#include "../inc.h"

class Solution {
   public:
    bool closeStrings(string word1, string word2) {}
};

void test(string word1, string word2, bool expect) {
    Solution so;
    auto ret = so.closeStrings(word1, word2);
    assert_eq_ret(expect, ret);
    print(word1);
    print(word2);
}

int main() {
    test("uau", "ssx", false);
    test("abc", "bca", true);
    test("a", "aa", false);
    test("cabbba", "abbccc", true);
    return 0;
}
