#include "../inc.h"

class Solution {
   public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        if (s1 == s2) return true;
        auto ssize = s1.size();
        for (size_t i = 0; i < ssize; ++i) {
            string s = s2.substr(i, ssize - i) + s2.substr(0, i);
            if (s == s1) return true;
        }
        return false;
    }
};

void test(string&& s1, string&& s2, bool expect) {
    save4print(s1, s2);
    auto ret = Solution().isFlipedString(s1, s2);
    assert_eq_ret(expect, ret);
}

int main() {
    test("", "", true);
    test("waterbottle", "erbottlewat", true);
    test("aa", "aba", false);
    return 0;
}
