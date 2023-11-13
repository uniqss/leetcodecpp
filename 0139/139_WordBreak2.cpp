#include "../inc.h"

/*
官方解法太不讲武德了，不过可以稍微优化一下
*/
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // 优化
        vector<bool> wlendict(21);
        for (const auto& word : wordDict) wlendict[word.size()] = true;

        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int end = 1; end <= n; ++end) {
            for (int begin = 0; begin < end; ++begin) {
                // 优化
                if (end - begin >= 21 || !wlendict[end - begin]) continue;

                if (dp[begin] && dict.count(s.substr(begin, end - begin)) > 0) {
                    dp[end] = true;
                    break;
                }
            }
        }
        return dp[n];
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
