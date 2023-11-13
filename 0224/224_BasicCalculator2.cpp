#include "../inc.h"

// 这题很有意思，当退化到只有小括号和加减的时候，可以直接跟穿甲弹一样，穿过小括号直接算结果
// 无视括号，只需要精确计算出每个数值加到一起就行了，括号只是改变了数值的正负
class Solution {
   public:
    int calculate(string s) {
        int ret = 0, sign = 1, val = 0;
        stack<int> signstk;
        signstk.emplace(1);
        int ssize = s.size();
        for (int i = 0; i < ssize;) {
            char c = s[i];
            if (c == ' ') {
            } else if (c == '+') {
                sign = signstk.top();
            } else if (c == '-') {
                sign = -signstk.top();
            } else if (c == '(') {
                signstk.emplace(sign);
            } else if (c == ')') {
                signstk.pop();
                sign = signstk.top();
            } else {
                val = 0;
                while (i < ssize && s[i] >= '0' && s[i] <= '9') {
                    val = val * 10 + (s[i] - '0');
                    ++i;
                }
                ret += sign * val;
                continue;
            }
            ++i;
        }
        return ret;
    }
};

void test(string s, int expect) {
    save4print(s);
    Solution so;
    auto ret = so.calculate(s);
    assert_eq_ret(expect, ret);
}
int main() {
    test("2147483647", 2147483647);
    test("1-(     -2)", 3);
    test("1+1", 2);
    test(" 2-1 + 2 ", 3);
    test("(1+(4+5+2)-3)+(6+8)", 23);
    return 0;
}