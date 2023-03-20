#include "../inc.h"

/*
这个算法极为完美，backtrace的经典体验。中文官方站上看到的。
好确实是好，问题在于，backtrace时，如何控制不重复性。
backtrace的模板：
void backtrace(vector<xxx>& ret, xxx& curr, int start, int end, int n){
    if (xxx.size() == n){
        ret.emplace_back(curr);
        return;
    }
    // 1
    if (some_condition(start, end, n, curr)){
        change_curr(curr);
        backtrace(ret, curr, start_changed, end_changed, n);
        change_back_curr(curr);
    }
    // 2
    for (some_condition(start, end, n, curr)){
        change_curr(curr);
        backtrace(ret, curr, start_changed, end_changed, n);
        change_back_curr(curr);
    }
}
大致是这样一个套路，if用法可以模拟类似本题的条件加删拼接操作，for用法可以模拟计算机对位的完整排列组合等，for的时候存一个used可以特殊剪枝，二叉树的dfs
一定要用计算机的思维去思考，才能掌握算法的本质。
*/
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string curr;
        backtrace(ret, curr, 0, 0, n);
        return ret;
    }
    void backtrace(vector<string>& ret, string& curr, int open, int close, int n) {
        if ((int)curr.size() == n * 2) {
            ret.emplace_back(curr);
            return;
        }
        if (open < n) {
            curr.push_back('(');
            backtrace(ret, curr, open + 1, close, n);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            backtrace(ret, curr, open, close + 1, n);
            curr.pop_back();
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
    test(4, {"(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()", "()((()))", "()(()())", "()(())()",
             "()()(())", "()()()()"});
    return 0;
}

/*
3
1

["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
*/
