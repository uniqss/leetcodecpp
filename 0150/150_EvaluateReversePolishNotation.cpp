#include "../inc.h"

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {}
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
