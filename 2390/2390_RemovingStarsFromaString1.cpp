#include "../inc.h"

class Solution {
   public:
    string removeStars(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '*') {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        if (stk.empty()) return "";
        string ret;
        while (!stk.empty()) {
            ret += stk.top();
            stk.pop();
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

void test(string s, string expect) {
    Solution so;
    auto ret = so.removeStars(s);
    assert_eq_ret(expect, ret);
    print(s);
}

int main() {
    test("leet**cod*e", "lecoe");
    test("erase*****", "");
    return 0;
}
