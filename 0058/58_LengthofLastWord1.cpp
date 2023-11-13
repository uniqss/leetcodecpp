#include "../inc.h"

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (ret > 0) return ret;
            } else {
                ++ret;
            }
        }
        return ret;
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
