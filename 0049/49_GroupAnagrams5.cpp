#include "../inc.h"

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for (const auto& s : strs) {
            auto k = s;
            sort(k.begin(), k.end());
            dict[k].emplace_back(s);
        }
        vector<vector<string>> ret;
        for (const auto& [_, v] : dict) ret.emplace_back(v);
        return ret;
    }
};

void test(vector<string>&& strs, vector<vector<string>>&& expect) {
    save4print(strs, expect);
    auto ret = Solution().groupAnagrams(strs);
    sortvvrawInnerAndOuter(expect);
    sortvvrawInnerAndOuter(ret);
    assert_eq_ret(expect, ret);
}

int main() {
    test({"", ""}, {{"", ""}});
    test({"eat", "tea", "tan", "ate", "nat", "bat"},
         {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}});
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
