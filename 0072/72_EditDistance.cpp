#include "../inc.h"

class Solution {
   public:
    int minDistance(string word1, string word2) {}
};

void test(string word1, string word2, int expect) {
    save4print(word1, word2);
    assert_eq_ret(expect, Solution().minDistance(word1, word2));
}

int main() {
    test("plasma", "altruism", 6);
    test("horse", "ros", 3);
    test("intention", "execution", 5);
    return 0;
}