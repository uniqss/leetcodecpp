#include "../inc.h"

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        char op[256] = {0};
        op['+'] = 1;
        op['-'] = 1;
        op['*'] = 1;
        op['/'] = 1;
        stack<int> stk;
        for (auto& token : tokens) {
            char c = token[0];
            if (op[c] > 0 && token.size() == 1) {
                int r = stk.top();
                stk.pop();
                int l = stk.top();
                stk.pop();
                if (c == '+') stk.push(l + r);
                if (c == '-') stk.push(l - r);
                if (c == '*') stk.push(l * r);
                if (c == '/') stk.push(l / r);
            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};

void test(vector<string>&& tokens, int expect) {
    Solution so;
    auto ret = so.evalRPN(tokens);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(tokens);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({"2", "1", "+", "3", "*"}, 9);
    test({"4", "13", "5", "/", "+"}, 6);
    test({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22);
    return 0;
}
