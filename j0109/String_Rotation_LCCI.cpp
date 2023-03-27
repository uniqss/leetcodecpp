#include "../inc.h"

class Solution {
   public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        if (s1 == s2) return true;
        // a b c d e  e a b c d
        for (size_t i = 1; i < s1.size(); ++i) {
            if (strncmp(s1.c_str(), s2.c_str() + i, s1.size() - i) != 0) continue;
            if (strncmp(s1.c_str() + s1.size() - i, s2.c_str(), i) != 0) continue;
            return true;
        }
        return false;
    }
};

void test(string&& s1, string&& s2, bool expect) {
    Solution so;
    auto ret = so.isFlipedString(s1, s2);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(s1);
        print(s2);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("ab", "ba", true);
    test("", "", true);
    test("waterbottle", "erbottlewat", true);
    test("aa", "aba", false);
    return 0;
}
