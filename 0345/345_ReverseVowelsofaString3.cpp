#include "../inc.h"

class Solution {
   public:
    string reverseVowels(string s) {
        unordered_set<char> dict = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (dict.count(s[l]) == 0) {
                ++l;
                continue;
            }
            if (dict.count(s[r]) == 0) {
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
