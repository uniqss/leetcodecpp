#include "../inc.h"

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;

        for (size_t i = 0; i < strs.size(); ++i) {
            string strKey(26, 'a');
            for (size_t j = 0; j < strs[i].size(); ++j) {
                size_t kidx = strs[i][j] - 'a';
                ++strKey[kidx];
            }
            mp[strKey].emplace_back(i);
        }

        vector<vector<string>> ret(mp.size());
        int idx = 0;
        for (const auto& it : mp) {
            for (size_t i = 0; i < it.second.size(); ++i) {
                ret[idx].push_back(strs[it.second[i]]);
            }
            ++idx;
        }

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
