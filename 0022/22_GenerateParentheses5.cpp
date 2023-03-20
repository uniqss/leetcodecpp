#include "../inc.h"

// recursive
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> tmp;
        helper(tmp, n);
        vector<string> ret;
        for (auto& it : tmp) {
            ret.emplace_back(it);
        }
        return ret;
    }
    void helper(unordered_set<string>& ret, int n) {
        if (n == 1) {
            ret = {"()"};
            return;
        }
        unordered_set<string> next;
        helper(next, n - 1);
        for (auto& it : next) {
            for (size_t i = 0; i < it.size(); ++i) {
                ret.insert(it.substr(0, i) + "()" + it.substr(i, it.size()));
            }
        }
    }
};

void test(int n, vector<string>&& expect) {
    Solution so;
    auto ret = so.generateParenthesis(n);

    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());

    if (ret != expect) {
        print("not ok.");
        print(n);
        print(expect);
        print(ret);
    } else {
        print("ok");
    }
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
