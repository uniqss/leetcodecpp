#include "../inc.h"

class Solution {
   public:
    vector<string> letterCombinations(string digits) {}
};

void test(string&& digits, vector<string>&& expected) {
    save4print(digits);
    auto ret = Solution().letterCombinations(digits);
    std::sort(ret.begin(), ret.end());
    std::sort(expected.begin(), expected.end());
    assert_eq_ret(expected, ret);
}

int main() {
    test("23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
    test("", {});
    test("2", {"a", "b", "c"});
    return 0;
}
