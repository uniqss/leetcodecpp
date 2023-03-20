#include "../inc/inc.h"

/*
dfs不递归的做法，略显繁琐，这里只记了left和right，并没有记它们的顺序，所以str不能省，否则在  curr = stk.top(); 的时候，就没法恢复了
*/
class Solution {
    struct Helper {
        string str;
        int left, right;
        bool valid(int n) { return left <= n && right <= n; }
    };

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        stack<Helper> stk;
        Helper curr = {"", 0, 0};
        while (curr.valid(n) || !stk.empty()) {
            while (curr.valid(n)) {
                stk.emplace(curr);
                ++curr.left;
                curr.str.push_back('(');
            }
            curr = stk.top();
            stk.pop();
            if (curr.left == n && curr.right == n) ret.emplace_back(curr.str);

            if (curr.left > curr.right) {
                ++curr.right;
                curr.str.push_back(')');
            } else {
                curr.right = INT_MAX;
            }
        }

        return ret;
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
    test(4, {"(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()", "()((()))", "()(()())", "()(())()",
             "()()(())", "()()()()"});
    return 0;
}

/*
3
1

["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
*/
