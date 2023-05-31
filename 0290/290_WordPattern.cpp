#include "../inc.h"

class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        vector<int> starts = {0};
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') starts.push_back(i + 1);
        }
        if (starts.size() != pattern.size()) return false;
        unordered_map<char, vector<int>> ptposes;
        for (int i = 0; i < pattern.size(); i++) {
            ptposes[pattern[i]].push_back(i);
        }
        for (auto it : ptposes) {
            if (it.second.size() == 1) continue;
            for (int i = 1; i < it.second.size(); i++) {
                
            }
        }
    }
};

void test(string pattern, string s, bool expect) {
    Solution so;
    auto ret = so.wordPattern(pattern, s);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(pattern);
        print(s);
        print(expect);
        print(ret);
    }
}

int main() {
    test("abba", "dog cat cat dog", true);
    test("abba", "dog cat cat fish", false);
    test("aaaa", "dog cat cat dog", false);

    return 0;
}
