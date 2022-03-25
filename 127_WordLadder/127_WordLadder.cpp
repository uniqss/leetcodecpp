#include "../inc.h"

class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {}
};

void test(string&& beginWord, string&& endWord, vector<string>&& wordList, int expect) {
    Solution so;
    auto ret = so.ladderLength(beginWord, endWord, wordList);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(beginWord);
        praw(endWord);
        pvraw(wordList);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test("a", "c", {"a", "b", "c"}, 2);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 5);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 0);
    return 0;
}
