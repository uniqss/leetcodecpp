#include "../inc.h"

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        vector<int> mdict(26), rdict(26);
        for (char c : magazine) ++mdict[c - 'a'];
        for (char c : ransomNote) {
            c -= 'a';
            if (++rdict[c] > mdict[c]) return false;
        }
        return true;
    }
};

void test(string ransomNote, string magazine, bool expect) {
    save4print(ransomNote);
    save4print(magazine);
    Solution so;
    auto ret = so.canConstruct(ransomNote, magazine);
    assert_eq_ret(expect, ret);
}

int main() {
    test(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        true);
    test("a", "b", false);
    test("aa", "ab", false);
    test("aa", "aab", true);
    return 0;
}
