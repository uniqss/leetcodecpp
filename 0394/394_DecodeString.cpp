#include "../inc.h"

class Solution {
   public:
    string decodeString(string s) {}
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
