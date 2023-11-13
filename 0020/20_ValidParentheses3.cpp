#include "../inc.h"

class Solution {
   public:
    bool isValid(string s) {
        static string sdict = "()[]{}";
        static unordered_map<char, char> dict;
        if (dict.empty())
            for (int i = 0; i < sdict.size(); i += 2) dict[sdict[i + 1]] = sdict[i];
        stack<char> stk;
        for (char c : s) {
            if (dict.count(c) == 0)
                stk.emplace(c);
            else {
                if (stk.empty() || stk.top() != dict[c]) return false;
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
