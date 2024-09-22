#include "../inc.h"

class Solution {
   public:
    bool isAnagram(const string& s, const string& t) {}
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