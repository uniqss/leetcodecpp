#include "../inc.h"

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {}
};

void test(string s, vector<string>&& words, vector<int>&& expect) {
    save4print(s);
    save4print(words);
    Solution so;
    auto ret = so.findSubstring(s, words);
    sort(expect.begin(), expect.end());
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test("barfoothefoobarman", {"foo", "bar"}, {0, 9});
    test("wordgoodgoodgoodbestword", {"word", "good", "best", "word"}, {});
    test("barfoofoobarthefoobarman", {"bar", "foo", "the"}, {6, 9, 12});
    return 0;
}
