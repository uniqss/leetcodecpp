#include "../inc.h"

// sort
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> strsTmp;
        for (size_t i = 0; i < strs.size(); ++i) {
            strsTmp.push_back({strs[i], i});
        }

        for (size_t i = 0; i < strsTmp.size(); ++i) {
            std::sort(strsTmp[i].first.begin(), strsTmp[i].first.end());
        }
        std::sort(strsTmp.begin(), strsTmp.end(),
                  [](const pair<string, int>& lhs, const pair<string, int>& rhs) {
                      return lhs.first < rhs.first;
                  });

        std::string strTmp;
        bool first = true;
        vector<vector<string>> ret;
        for (size_t i = 0; i < strsTmp.size(); ++i) {
            if (first || strsTmp[i].first != strTmp) {
                first = false;
                strTmp = strsTmp[i].first;
                ret.push_back({strs[strsTmp[i].second]});
            } else {
                ret[ret.size() - 1].push_back(strs[strsTmp[i].second]);
            }
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
