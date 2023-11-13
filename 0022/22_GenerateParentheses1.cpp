#include "../inc.h"

// 一维dp的解法  这题应该也可以递归，但性能比较差
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<unordered_set<string>> dp(n);
        dp[0].insert("()");
        for (size_t i = 1; i < n; ++i) {
            for (auto& str : dp[i - 1]) {
                for (size_t pos = 0; pos < str.size(); ++pos) {
                    dp[i].insert(str.substr(0, pos) + "()" + str.substr(pos, str.size()));
                }
                dp[i].insert(str + "()");
            }
        }
        vector<string> ret(dp[n - 1].begin(), dp[n - 1].end());
        return ret;
    }
};

void test(int n, vector<string>&& expect) {
    save4print(n);
    auto ret = Solution().generateParenthesis(n);
    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test(1, {"()"});
    test(2, {"(())", "()()"});
    test(3, {"((()))", "(()())", "(())()", "()(())", "()()()"});
    test(4, {"(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()", "()((()))", "()(()())", "()(())()", "()()(())", "()()()()"});
    return 0;
}

/*
3
1

["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
*/
