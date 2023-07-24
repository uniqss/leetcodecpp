#include "../inc.h"

class Solution {
   public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        vector<bool> dict(256, false);
        dict['a'] = true;
        dict['A'] = true;
        dict['e'] = true;
        dict['E'] = true;
        dict['i'] = true;
        dict['I'] = true;
        dict['o'] = true;
        dict['O'] = true;
        dict['u'] = true;
        dict['U'] = true;
        while (l < r) {
            if (!dict[s[l]]) {
                ++l;
                continue;
            }
            if (!dict[s[r]]) {
                --r;
                continue;
            }
            swap(s[l], s[r]);
            ++l, --r;
        }
        return s;
    }
};

void test(string s, string expect) {
    Solution so;
    auto ret = so.reverseVowels(s);
    assert_eq_ret(expect, ret);
    print(s);
}

int main() {
    test("hello", "holle");
    test("leetcode", "leotcede");
    return 0;
}
