#include "../inc.h"

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        // s.length == t.length
        if (s.empty()) return true;
        char dict[256] = {0};
        bool tused[256] = {false};
        for (size_t i = 0; i < s.size(); i++) {
            if (dict[s[i]] != 0) {
                if (dict[s[i]] != t[i]) return false;
            } else {
                if (tused[t[i]]) return false;
                dict[s[i]] = t[i];
                tused[t[i]] = true;
            }
        }

        return true;
    }
};

void test(string s, string t, bool expect) {
    save4print(s);
    save4print(t);
    Solution so;
    auto ret = so.isIsomorphic(s, t);
    assert_eq_ret(expect, ret);
}

int main() {
    test("badc", "baba", false);
    test("egg", "add", true);
    test("foo", "bar", false);
    test("paper", "title", true);
    return 0;
}
