#include "../inc.h"

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {}
};

void test(vector<string>&& strs, string expect) {
    save4print(strs);
    Solution so;
    auto ret = so.longestCommonPrefix(strs);
    assert_eq_ret(expect, ret);
}

int main() {
    test({"flower", "flow", "flight"}, "fl");
    test({"a"}, "a");
    test({"flower", "flow", "flight"}, "fl");
    test({"dog", "racecar", "car"}, "");
    return 0;
}
