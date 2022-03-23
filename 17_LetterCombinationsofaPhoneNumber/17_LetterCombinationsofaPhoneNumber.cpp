#include "../inc.h"

class Solution {
   public:
    vector<string> letterCombinations(string digits) {}
};

void test(string&& digits, vector<string>&& expected) {
    Solution so;
    auto ret = so.letterCombinations(digits);
    std::sort(ret.begin(), ret.end());
    std::sort(expected.begin(), expected.end());
    if (ret == expected) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(digits);
        pvraw(expected);
        pvraw(ret);
    }
}

int main() {
    test("23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
    test("", {});
    test("2", {"a", "b", "c"});
    return 0;
}
