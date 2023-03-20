#include "../inc/inc.h"

// map diff
class Solution {
   public:
    bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> countDiff;
        for (size_t i = 0; i < s.size(); ++i) {
            ++countDiff[s[i]];
            --countDiff[t[i]];
        }
        for (auto it : countDiff) {
            if (it.second != 0) return false;
        }

        return true;
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