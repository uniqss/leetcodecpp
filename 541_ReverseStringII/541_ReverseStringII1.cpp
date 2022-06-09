#include "../inc.h"

class Solution {
   public:
    string reverseStr(string s, int k) {
        int k2 = k << 1;
        for (size_t i = 0; i < s.size(); i += k2) {
            if (i + k < s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

void test(string&& s, int k, const string& expect) {
    Solution so;
    auto ret = so.reverseStr(s, k);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(s);
        praw(k);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test("abcdefg", 2, "bacdfeg");
    test("abcd", 2, "bacd");
    return 0;
}
