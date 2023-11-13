#include "../inc.h"

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {}
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
