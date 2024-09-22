#include "../inc.h"

// not suggested...
class Solution {
   public:
    int lengthOfLastWord(string s) {
        int r = s.size() - 1, l = 0;
        while (s[r] == ' ') --r;
        l = r;
        while (l >= 0 && s[l] != ' ') --l;
        return r - l;
    }
};

void test(string&& s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().lengthOfLastWord(s));
}

int main() {
    test("Hello World", 5);
    test("   fly me   to   the moon  ", 4);
    test("luffy is still joyboy", 6);
    test("a", 1);
    return 0;
}
