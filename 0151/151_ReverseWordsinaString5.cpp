#include "../inc.h"

class Solution {
   public:
    string reverseWords(string s) {
        int valid = 0;
        bool lastblank = false;
        int i = 0;
        while (s[i] == ' ') ++i;
        for (; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (lastblank) s[valid++] = ' ';
                s[valid++] = s[i];
                lastblank = false;
            } else {
                lastblank = true;
            }
        }
        s = s.substr(0, valid);
        reverse(s.begin(), s.end());
        lastblank = false;
        int start = 0;
        for (i = 1; i < valid; ++i) {
            if (s[i] != ' ') {
                if (lastblank) {
                    reverse(s.begin() + start, s.begin() + i - 1);
                    start = i;
                }

                lastblank = false;
            } else {
                lastblank = true;
            }
        }
        reverse(s.begin() + start, s.end());

        return s;
    }
};

void test(string&& s, string expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().reverseWords(s));
}

int main() {
    test("a", "a");
    test("the sky is blue", "blue is sky the");
    test("  hello world  ", "world hello");
    test("a good   example", "example good a");
    test("example good a", "a good example");
    return 0;
}
