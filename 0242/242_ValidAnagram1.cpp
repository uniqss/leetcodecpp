#include "../inc.h"

// brute-force
class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};

void test(const string& s, const string& t, bool expect) {
    save4print(s, t);
    assert_eq_ret(expect, Solution().isAnagram(s, t));
}

int main() {
    test("anagram", "nagaram", true);
    test("rat", "car", false);
    return 0;
}
/*
"anagram"
"nagaram"
"rat"
"car"
*/