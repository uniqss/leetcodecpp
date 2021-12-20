#include "../stl.h"

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<pair<unordered_map<char, size_t>, size_t>> strCount(strs.size());
        for (size_t i = 0; i < strs.size(); ++i) {
            strCount[i].second = i;
            for (size_t j = 0; j < strs[i].size(); ++j) {
                ++strCount[i].first[strs[i][j]];
            }
        }
        std::sort(strCount.begin(), strCount.end(), [](pair<unordered_map<char, size_t>, size_t>& lhs, pair<unordered_map<char, size_t>, size_t>& rhs) {
            return lhs.first == rhs.first;
        });
        for (size_t i = 0; i < strCount.size(); ++i) {
            if (i == 0 || strCount[i].first != strCount[i - 1].first) {
                ret.push_back({strs[strCount[i].second]});
            } else {
                ret[ret.size() - 1].push_back(strs[strCount[i].second]);
            }
        }
        return ret;
    }
};

void test(vector<string>&& strs, const vector<vector<string>>& expect) {
    Solution s;
    auto ret = s.groupAnagrams(strs);
    if (ret != expect) {
        praw("not ok.");
        pvraw(strs);
        pvvraw(expect);
        pvvraw(ret);
    } else {
        praw("ok.");
    }
}

int main() {
    test({"eat","tea","tan","ate","nat","bat"}, {{"bat"}, {"nat","tan"}, {"ate","eat","tea"}});
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
