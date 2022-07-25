#include "../inc.h"

class Solution {
   public:
    bool isAnagram(const string& s, const string& t) {}
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