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
    Solution so;
    bool ret = so.isAnagram(s, t);
    if (ret == expect) {
        print("ok");
    } else {
        print("##### not ok.");
        print(s);
        print(t);
        print(expect);
        print(ret);
    }
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