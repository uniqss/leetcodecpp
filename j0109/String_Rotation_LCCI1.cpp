#include "../inc.h"

class Solution {
   public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        if (s1 == s2) return true;
        auto ssize = s1.size();
        for (size_t i = 0; i < ssize; ++i) {
            string s = s2.substr(i, ssize - i) + s2.substr(0, i);
            if (s == s1) return true;
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
    test("", "", true);
    test("waterbottle", "erbottlewat", true);
    test("aa", "aba", false);
    return 0;
}
