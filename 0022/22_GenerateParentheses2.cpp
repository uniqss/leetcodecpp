#include "../inc.h"

// 本质上还是dp，只不过没有保存所有结果
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> ss;
        ss.insert("()");
        for (int i = 2; i <= n; ++i) {
            unordered_set<string> last = ss;
            ss.clear();
            for (const string& str : last) {
                for (size_t i = 0; i < str.size(); ++i) {
                    string tmp = str.substr(0, i) + "()" + str.substr(i, str.size());
                    ss.insert(tmp);
                }
            }
        }
        vector<string> ret;
        for (const auto& str : ss) {
            ret.push_back(str);
        }
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
