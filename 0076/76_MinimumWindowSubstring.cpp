#include "../inc.h"

class Solution {
   public:
    string minWindow(string s, string t) {}
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
