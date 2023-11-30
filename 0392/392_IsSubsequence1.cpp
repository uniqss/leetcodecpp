#include "../inc.h"

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) return false;
        if (s.size() == t.size()) return s == t;
        int si = 0, ti = 0, ssize = s.size(), tsize = t.size();
        while (ti < tsize) {
            if (t[ti] == s[si]) ++si;
            ++ti;
        }
        return si == ssize;
    }
};

void test(string s, string t, bool expect) {
    save4print(s, t);
    assert_eq_ret(expect, Solution().isSubsequence(s, t));
}

int main() {
    test("", "ahbgdc", true);
    test("abc", "ahbgdc", true);
    test("axc", "ahbgdc", false);
    return 0;
}
