#include "../inc.h"

// sort 2
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (size_t i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            std::sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for (auto& it : mp) {
            ret.push_back(it.second);
        }
        return ret;
    }
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
