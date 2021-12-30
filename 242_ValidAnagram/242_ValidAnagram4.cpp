#include "../stl.h"

// array[26] diff
class Solution {
   public:
    bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) return false;
        char as[26] = {0};
        for (size_t i = 0; i < s.size(); ++i) {
            ++as[s[i] - 'a'];
            --as[t[i] - 'a'];
        }
        char at[26] = {0};
        return !memcmp(as, at, sizeof(as));
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