#include "../inc.h"

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
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
