#include "../inc.h"

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {}
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
