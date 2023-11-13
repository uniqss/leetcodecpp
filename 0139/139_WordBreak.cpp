#include "../inc.h"

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {}
};

void test(string s, vector<string>&& wordDict, bool expect) {
    save4print(s, wordDict);
    assert_eq_ret(expect, Solution().wordBreak(s, wordDict));
}

int main() {
    test(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
        {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"}, false);
    test("leetcode", {"leet", "code"}, true);
    test("applepenapple", {"apple", "pen"}, true);
    test("catsandog", {"cats", "dog", "sand", "and", "cat"}, false);
    return 0;
}
