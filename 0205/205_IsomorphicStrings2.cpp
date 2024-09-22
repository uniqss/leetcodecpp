#include "../inc.h"

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < n; ++i) {
            char si = s[i], ti = t[i];
            auto it = s2t.find(si);
            if (it != s2t.end() && it->second != ti) return false;
            auto it2 = t2s.find(ti);
            if (it2 != t2s.end() && it2->second != si) return false;
            s2t[si] = ti;
            t2s[ti] = si;
        }
        return true;
    }
};

void test(string s, string t, bool expect) {
    save4print(s, t);
    assert_eq_ret(expect, Solution().isIsomorphic(s, t));
}

int main() {
    test("badc", "baba", false);
    test("egg", "add", true);
    test("foo", "bar", false);
    test("paper", "title", true);
    return 0;
}
