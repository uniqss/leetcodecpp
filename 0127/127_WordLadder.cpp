#include "../inc.h"

class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {}
};

void test(string&& beginWord, string&& endWord, vector<string>&& wordList, int expect) {
    save4print(beginWord, endWord, wordList);
    assert_eq_ret(expect, Solution().ladderLength(beginWord, endWord, wordList));
}

int main() {
    test("a", "c", {"a", "b", "c"}, 2);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 5);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 0);
    return 0;
}
