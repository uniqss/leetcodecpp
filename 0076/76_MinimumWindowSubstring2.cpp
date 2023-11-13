#include "../inc.h"

class Solution {
   public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return "";
        vector<int> scount(256), tcount(256);
        for (char c : t) ++tcount[c];
        int start = 0, mlen = INT_MAX, mstart = 0, needed = n, curr = 0;
        for (int i = 0; i < m; ++i) {
            if (tcount[s[i]] > 0 && scount[s[i]] < tcount[s[i]]) ++curr;
            ++scount[s[i]];
            while (scount[s[start]] > tcount[s[start]]) {
                --scount[s[start]];
                ++start;
            }
            if (curr >= needed) {
                if (mlen > i - start + 1) {
                    mlen = i - start + 1;
                    mstart = start;
                }
            }
        }
        return mlen != INT_MAX ? s.substr(mstart, mlen) : "";
    }
};

void test(string s, string t, const string& expect) {
    save4print(s, t);
    assert_eq_ret(expect, Solution().minWindow(s, t));
}

int main() {
    test("acbbaca", "aba", "baca");
    test("bba", "ab", "ba");
    test("ADOBECODEBANC", "ABC", "BANC");
    test("a", "a", "a");
    test("a", "aa", "");
    return 0;
}
