#include "../inc.h"

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i <= n; ++i) {
            if (dp[i]) {
                for (const auto& wd : wordDict) {
                    if (n - i >= wd.size()) {
                        if (s.substr(i, wd.size()) == wd) {
                            if (i + wd.size() == n) return true;
                            dp[i + wd.size()] = true;
                        }
                    }
                }
            }
        }
        return false;
    }
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
