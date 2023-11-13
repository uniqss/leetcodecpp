#include "../inc.h"

/*
backtrace和dfs看看的角度，其实有时候是一样的
*/
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string t;
        dfs(ret, t, 0, 0, 0, n);
        return ret;
    }
    void dfs(vector<string>& ret, string& t, int curr, int left, int right, int n) {
        if (curr == n * 2) {
            ret.emplace_back(t);
            return;
        }
        if (left < n) {
            t.push_back('(');
            dfs(ret, t, curr + 1, left + 1, right, n);
            t.pop_back();
        }
        if (left > right) {
            t.push_back(')');
            dfs(ret, t, curr + 1, left, right + 1, n);
            t.pop_back();
        }
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
    test(4, {"(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()", "()((()))", "()(()())", "()(())()",
             "()()(())", "()()()()"});
    return 0;
}

/*
3
1

["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
*/
