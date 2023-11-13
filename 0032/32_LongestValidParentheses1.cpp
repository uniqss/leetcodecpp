#include "../inc.h"

class Solution {
   public:
    int longestValidParentheses(string s) {
        int n = s.size(), ret = 0;
        vector<int> maxend(n);
        auto dpi = [&maxend](int i) { return i >= 0 ? maxend[i] : 0; };
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    // () 只碰不吃          ...)()
                    maxend[i] = dpi(i - 2) + 2;
                } else if (i - maxend[i - 1] - 1 >= 0 && s[i - maxend[i - 1] - 1] == '(') {
                    // )) 又碰又吃            ...)((...))
                    maxend[i] = maxend[i - 1] + dpi(i - maxend[i - 1] - 2) + 2;
                }
                ret = max(ret, maxend[i]);
            }
        }

        return ret;
    }
};

void test(string s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().longestValidParentheses(s));
}

int main() {
    test("((()))())", 8);
    test("()(())", 6);
    test("()", 2);
    test("(()", 2);
    test(")()())", 4);
    test("", 0);
    return 0;
}
