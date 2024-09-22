#include "../inc.h"

class Solution {
    struct LowerStrHash {
        int vals[26];
        bool operator==(const LowerStrHash& rhs) const {
            for (int i = 0; i < 26; ++i)
                if (vals[i] != rhs.vals[i]) return false;
            return true;
        }
    };
    struct LowerStrHashFunctor {
        size_t operator()(const LowerStrHash& v) const {
            size_t ret = 0;
            for (int i = 0; i < 26; ++i) ret ^= std::hash<int>()(v.vals[i]);
            return ret;
        }
    };

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<LowerStrHash, vector<string>, LowerStrHashFunctor> dict;
        for (auto s : strs) {
            LowerStrHash h = {0};
            for (char c : s) ++h.vals[c - 'a'];
            dict[h].emplace_back(s);
        }
        vector<vector<string>> ret;
        for (auto it : dict) ret.push_back(it.second);
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
