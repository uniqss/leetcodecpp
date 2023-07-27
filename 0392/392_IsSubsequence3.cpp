#include "../inc.h"

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        int ssize = s.size(), tsize = t.size(), si = 0, ti = 0;
        if (ssize > tsize) return false;
        while (ti < tsize) {
            if (s[si] == t[ti]) {
                if (++si >= ssize) return true;
            }
            ++ti;
        }
        return false;
    }
};

void test(string s, string t, bool expect) {
    Solution so;
    auto ret = so.isSubsequence(s, t);
    assert_eq_ret(expect, ret);
    print(s);
    print(t);
}

int main() {
    test("", "ahbgdc", true);
    test("abc", "ahbgdc", true);
    test("axc", "ahbgdc", false);
    return 0;
}
