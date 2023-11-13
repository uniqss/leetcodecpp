#include "../inc.h"

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        vector<int> scount(26), pcount(26);
        for (char c : p) ++pcount[c - 'a'];
        int ssize = s.size(), psize = p.size();
        for (int i = 0; i < ssize; ++i) {
            ++scount[s[i] - 'a'];
            if (i >= psize) --scount[s[i - psize] - 'a'];
            if (scount== pcount) {
                ret.emplace_back(i - psize + 1);
            }
        }
        return ret;
    }
};

void test(string s, string p, const vector<int>& expect) {
    Solution so;
    auto ret = so.findAnagrams(s, p);
    assert_eq_ret(expect, ret);
    print(s, p);
}

int main() {
    test("cbaebabacd", "abc", {0, 6});
    test("abab", "ab", {0, 1, 2});
    return 0;
}
