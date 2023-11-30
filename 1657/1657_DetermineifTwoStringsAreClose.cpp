#include "../inc.h"

class Solution {
   public:
    bool closeStrings(string word1, string word2) {}
};

void test(string word1, string word2, bool expect) {
    save4print(word1, word2);
    assert_eq_ret(expect, Solution().closeStrings(word1, word2));
}

int main() {
    test("uau", "ssx", false);
    test("abc", "bca", true);
    test("a", "aa", false);
    test("cabbba", "abbccc", true);
    return 0;
}
