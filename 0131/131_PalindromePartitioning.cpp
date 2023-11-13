#include "../inc.h"

class Solution {
   public:
    vector<vector<string>> partition(string s) {}
};

void test(string s, vector<vector<string>>&& expect) {
    save4print(s);
    sort(expect.begin(), expect.end());
    auto ret = Solution().partition(s);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test("abbab", {{"a", "b", "b", "a", "b"}, {"a", "b", "bab"}, {"a", "bb", "a", "b"}, {"abba", "b"}});
    test("aab", {{"a", "a", "b"}, {"aa", "b"}});
    test("a", {{"a"}});
    return 0;
}