#include "../inc.h"

class Solution {
   public:
    string reverseVowels(string s) {
        unordered_set<char> dict = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (dict.count(s[l]) == 0 && l < r) ++l;
            while (dict.count(s[r]) == 0 && l < r) --r;
            swap(s[l], s[r]);
            ++l, --r;
        }
        return s;
    }
};

void test(string s, string expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().reverseVowels(s));
}

int main() {
    test("hello", "holle");
    test("leetcode", "leotcede");
    return 0;
}
