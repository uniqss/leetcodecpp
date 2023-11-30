#include "../inc.h"

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {}
};

void test(string&& word1, string&& word2, const string& expect) {
    save4print(word1, word2);
    assert_eq_ret(expect, Solution().mergeAlternately(word1, word2));
}

int main() {
    test("abc", "pqr", "apbqcr");
    test("ab", "pqrs", "apbqrs");
    test("abcd", "pq", "apbqcd");
    return 0;
}
