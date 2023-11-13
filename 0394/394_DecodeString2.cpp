#include "../inc.h"

/*
deque 略重，stack更佳
*/
class Solution {
   public:
    string decodeString(string s) {
        deque<pair<string, int>> q;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                if (q.empty() || q.back().second != 0) {
                    q.emplace_back(string(1, c), 0);
                } else {
                    q.back().first += c;
                }
            } else if (c >= '0' && c <= '9') {
                if (q.empty() || q.back().second == 0) {
                    q.emplace_back("", c - '0');
                } else {
                    q.back().second = q.back().second * 10 + c - '0';
                }
            } else if (c == '[') {
                q.emplace_back("", 0);
            } else {
                string origin = q.back().first, repeated = origin;
                q.pop_back();
                int repeat = q.back().second;
                for (int i = 1; i < repeat; ++i) {
                    repeated += origin;
                }
                q.pop_back();
                if (q.empty() || q.back().second != 0) {
                    q.emplace_back(repeated, 0);
                } else {
                    q.back().first += repeated;
                }
            }
        }
        return q.back().first;
    }
};

void test(string s, string expect) {
    Solution so;
    auto ret = so.decodeString(s);
    assert_eq_ret(expect, ret);
    print(s);
}

int main() {
    test("abc3[cd]xyz", "abccdcdcdxyz");
    test("3[z]2[2[y]pq4[2[jk]e1[f]]]ef", "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef");
    test("3[a]2[bc]", "aaabcbc");
    test("3[a2[c]]", "accaccacc");
    test("2[abc]3[cd]ef", "abcabccdcdcdef");
    return 0;
}
