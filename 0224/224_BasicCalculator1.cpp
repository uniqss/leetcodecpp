#include "../inc.h"

class Solution {
   public:
    int calculate(string s) {
        if (s.empty()) return 0;
        vector<pair<string, int>> vs;
        s = "(" + s + ")";
        int idx = 0, ssize = s.size();
        while (idx < ssize) {
            if (s[idx] == '+' || s[idx] == '(' || s[idx] == ')')
                vs.emplace_back(string(1, s[idx]), 0);
            else if (s[idx] == '-') {
                if (vs.empty() || vs.back().first == "(") {
                    vs.emplace_back("", 0);
                }
                vs.push_back({"-", 0});
            } else if (s[idx] >= '0' && s[idx] <= '9') {
                int num = 0;
                while (s[idx] >= '0' && s[idx] <= '9') {
                    num *= 10;
                    num += s[idx] - '0';
                    ++idx;
                }
                vs.push_back({"", num});
                continue;
            }
            ++idx;
        }

        int vsize = vs.size();
        stack<pair<string, int>> stk;
        for (int i = 0; i < vsize; ++i) {
            const auto& [str, num] = vs[i];
            if (str == "+" || str == "-" || str == "(" || str.empty()) {
                stk.emplace(str, num);
            } else if (str == ")") {
                stack<pair<string, int>> stkcurr;
                while (!stk.empty()) {
                    if (stk.top().first == "(") {
                        stk.pop();
                        break;
                    }
                    stkcurr.emplace(stk.top());
                    stk.pop();
                }
                int currval = 0;
                if (stkcurr.top().first.empty()) stkcurr.emplace("+", 0);
                while (!stkcurr.empty()) {
                    string op = stkcurr.top().first;
                    stkcurr.pop();
                    int rhs = stkcurr.top().second;
                    stkcurr.pop();
                    if (op == "+") {
                        currval += rhs;
                    } else if (op == "-") {
                        currval -= rhs;
                    }
                }
                stk.emplace("", currval);
            }
        }

        return stk.top().second;
    }
};

void test(string s, int expect) {
    save4print(s);
    Solution so;
    auto ret = so.calculate(s);
    assert_eq_ret(expect, ret);
}
int main() {
    test("1-(     -2)", 3);
    test("1+1", 2);
    test(" 2-1 + 2 ", 3);
    test("(1+(4+5+2)-3)+(6+8)", 23);
    return 0;
}