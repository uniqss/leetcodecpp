#include "../inc.h"

// 这才像是人写的代码嘛
class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_map<string, std::function<int(int, int)>> ops;
        ops["+"] = [](int lhs, int rhs) -> int { return lhs + rhs; };
        ops["-"] = [](int lhs, int rhs) -> int { return lhs - rhs; };
        ops["*"] = [](int lhs, int rhs) -> int { return lhs * rhs; };
        ops["/"] = [](int lhs, int rhs) -> int { return lhs / rhs; };
        for (const auto& tk : tokens) {
            auto it = ops.find(tk);
            if (it != ops.end()) {
                int rhs = stk.top();
                stk.pop();
                int lhs = stk.top();
                stk.pop();
                int curr = it->second(lhs, rhs);
                stk.emplace(curr);
            } else {
                stk.emplace(std::atoi(tk.c_str()));
            }
        }
        return stk.top();
    }
};

void test(vector<string>&& tokens, int expect) {
    save4print(tokens);
    Solution so;
    auto ret = so.evalRPN(tokens);
    assert_eq_ret(expect, ret);
}

int main() {
    test({"2", "1", "+", "3", "*"}, 9);
    test({"4", "13", "5", "/", "+"}, 6);
    test({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22);
    return 0;
}
