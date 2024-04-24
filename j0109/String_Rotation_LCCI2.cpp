#include "../inc.h"

class Solution {
   public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        if (s1 == s2) return true;
        auto ssize = s1.size();
        for (size_t i = 1; i < ssize; ++i) {
            if (strncmp(s2.data(), s1.data() + ssize - i, i) != 0) continue;
            if (strncmp(s2.data() + i, s1.data(), ssize - i) != 0) continue;
            return true;
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
