#include "../inc.h"

class Solution {
   public:
    string decodeString(string s) {
        stack<pair<string, int>> stk;
        int num = 0;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                if (stk.empty() || stk.top().second == 0)
                    stk.push({"", (int)(c - '0')});
                else
                    stk.top().second = stk.top().second * 10 + c - '0';
            } else if (c >= 'a' && c <= 'z') {
                if (stk.empty() || stk.top().second > 0) {
                    stk.push({string() + c, 0});
                } else
                    stk.top().first += c;
            } else if (c == '[') {
                stk.push({"", 0});
            } else if (c == ']') {
                auto str = stk.top().first;
                stk.pop();
                string repeat = str;
                for (int i = 1; i < stk.top().second; ++i) repeat += str;
                stk.pop();
                if (stk.empty())
                    stk.push({repeat, 0});
                else {
                    if (stk.top().second == 0)
                        stk.top().first += repeat;
                    else {
                        // print("error");
                    }
                }
            }
        }
        return stk.top().first;
    }
};

void test(string s, string expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().decodeString(s));
}

int main() {
    test("abc3[cd]xyz", "abccdcdcdxyz");
    test("3[z]2[2[y]pq4[2[jk]e1[f]]]ef", "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef");
    test("3[a]2[bc]", "aaabcbc");
    test("3[a2[c]]", "accaccacc");
    test("2[abc]3[cd]ef", "abcabccdcdcdef");
    return 0;
}
