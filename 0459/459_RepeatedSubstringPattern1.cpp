#include "../inc/inc.h"

class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if (n <= 1) return false;

        vector<int> next(n);
        next[0] = 0;
        for (int i = 1, j = 0; i < n; ++i) {
            while (j > 0 && s[i] != s[j]) j = next[j - 1];
            if (s[i] == s[j]) ++j;
            next[i] = j;
        }

        if (next[n - 1] == 0) return false;

        int range = n - next[n - 1];
        return range > 0 && next[n - 1] % range == 0;
    }
};

void test(string&& s, bool expect) {
    Solution so;
    auto ret = so.repeatedSubstringPattern(s);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(s);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("abac", false);
    test("abab", true);
    test("abcabcabcabc", true);
    return 0;
}
