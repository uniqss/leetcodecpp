#include "../stl.h"

class Solution {
   public:
    bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, size_t> maps;
        unordered_map<char, size_t> mapt;
        for (size_t i = 0; i < s.size(); ++i) {
            ++maps[s[i]];
        }
        for (size_t i = 0; i < t.size(); ++i) {
            ++mapt[t[i]];
        }
        return maps == mapt;
    }
};

void test(const string& s, const string& t, bool expect) {
    Solution so;
    bool ret = so.isAnagram(s, t);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("##### not ok.");
        praw(s);
        praw(t);
        praw(expect);
        praw(ret);
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