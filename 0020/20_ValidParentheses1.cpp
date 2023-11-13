#include "../inc.h"

class Solution {
   public:
    bool isValid(string s) {
        unordered_map<char, char> dict;
        dict['('] = ')';
        dict['['] = ']';
        dict['{'] = '}';
        stack<char> stackc;
        for (size_t i = 0; i < s.size(); ++i) {
            auto it = dict.find(s[i]);
            if (it != dict.end()) {
                // left
                stackc.push(it->second);
            } else {
                // right, match top
                if (stackc.empty()) return false;
                if (stackc.top() != s[i]) {
                    return false;
                }
                stackc.pop();
            }
        }
        return stackc.empty();
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