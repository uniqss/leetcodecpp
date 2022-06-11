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
    Solution so;
    bool ret = so.isValid(s);
    if (expected != ret) {
        praw("!!!!!!! not ok");
        praw(s);
        praw(expected);
        praw(ret);
        pnewline();
    } else {
        praw("ok");
    }
}

int main() {
    test("()", true);
    test("()[]{}", true);
    test("(]", false);
    return 0;
}