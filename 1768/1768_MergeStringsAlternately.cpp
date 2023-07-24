#include "../inc.h"

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {}
};

void test(string&& word1, string&& word2, const string& expect) {
    Solution so;
    auto ret = so.mergeAlternately(word1, word2);
    assert_eq_ret(expect, ret);
    print(word1);
    print(word2);
}

int main() {
    test("abc", "pqr", "apbqcr");
    test("ab", "pqrs", "apbqrs");
    test("abcd", "pq", "apbqcd");
    return 0;
}
