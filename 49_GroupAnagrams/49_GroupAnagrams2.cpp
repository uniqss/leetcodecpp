#include "../stl.h"

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
        std::sort(strsTmp.begin(), strsTmp.end(), [](const pair<string, int>& lhs, const pair<string, int>& rhs) {
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

void test(vector<string>&& strs, const vector<vector<string>>& expect) {
    Solution s;
    auto ret = s.groupAnagrams(strs);
    set<set<string>> mapexpect;
    set<set<string>> mapret;
    for (const auto& it : expect) {
        set<string> ss;
        for (const auto& iti : it) {
            ss.insert(iti);
        }
        mapexpect.insert(ss);
    }
    for (const auto& it : ret) {
        set<string> ss;
        for (const auto& iti : it) {
            ss.insert(iti);
        }
        mapret.insert(ss);
    }

    if (mapret != mapexpect) {
        praw("not ok.");
        pvraw(strs);
        pvvraw(expect);
        pvvraw(ret);
    } else {
        praw("ok.");
    }
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
