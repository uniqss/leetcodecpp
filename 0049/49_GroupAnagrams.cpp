#include "../inc.h"

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {}
};

void test(vector<string>&& strs, vector<vector<string>>&& expect) {
    save4print(strs);
    save4print(expect);
    Solution s;
    auto ret = s.groupAnagrams(strs);
    sortvvrawInnerAndOuter(expect);
    sortvvrawInnerAndOuter(ret);
    assert_eq_ret(expect, ret);
}

int main() {
    test({"", ""}, {{"", ""}});
    test({"eat", "tea", "tan", "ate", "nat", "bat"}, {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}});
    test({""}, {{""}});
    test({"a"}, {{"a"}});
    return 0;
}
/*
["eat","tea","tan","ate","nat","bat"]
[""]
["a"]

["bat"],["nat","tan"],["ate","eat","tea"]
*/
