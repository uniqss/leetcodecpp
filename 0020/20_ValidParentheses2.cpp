#include "../inc.h"

// 这其实是c的解法了
class Solution {
   public:
    bool isValid(string s) {
        char dictLeft[256] = {0};
        dictLeft['('] = ')';
        dictLeft['['] = ']';
        dictLeft['{'] = '}';
        stack<char> stk;
        for (char c : s) {
            if (dictLeft[c] > 0)
                stk.push(c);
            else {
                if (stk.empty()) return false;
                if (dictLeft[stk.top()] != c) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

void test(const string& s, bool expected) {
    save4print(s);
    Solution so;
    bool ret = so.isValid(s);
    assert_eq_ret(expected, ret);
}

int main() {
    test("]", false);
    test("()", true);
    test("()[]{}", true);
    test("(]", false);
    return 0;
}
