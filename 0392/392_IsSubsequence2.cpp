#include "../inc.h"

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        int ssize = s.size(), tsize = t.size(), i = 0, j = 0;
        while (j < tsize) {
            if (t[j] == s[i]) {
                ++i;
                if (i == ssize) return true;
            }
            ++j;
        }
        return false;
    }
};

void test(string s, string t, bool expect) {
    save4print(s);
    save4print(t);
    Solution so;
    auto ret = so.isSubsequence(s, t);
    assert_eq_ret(expect, ret);
}

int main() {
    test("", "ahbgdc", true);
    test("abc", "ahbgdc", true);
    test("axc", "ahbgdc", false);
    return 0;
}
