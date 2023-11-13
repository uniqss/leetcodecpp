#include "../inc.h"

class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        vector<int> starts = {0};
        auto ssize = s.size();
        s.push_back(' ');
        for (int i = 0; i < ssize; i++) {
            if (s[i] == ' ') starts.push_back(i + 1);
        }
        if (starts.size() != pattern.size()) return false;
        vector<int> ptposes[26];
        for (int i = 0; i < pattern.size(); i++) {
            ptposes[pattern[i] - 'a'].push_back(i);
        }
        for (auto& it : ptposes) {
            if (it.size() <= 1) continue;
            auto pos0 = it[0];
            for (int i = 1; i < it.size(); i++) {
                auto start0 = starts[pos0];
                auto start = starts[it[i]];
                while (start < ssize && start0 < ssize && s[start] != ' ' && s[start0] != ' ') {
                    if (s[start] != s[start0]) return false;
                    ++start;
                    ++start0;
                }
                if (s[start] != ' ' || s[start0] != ' ') return false;
            }
        }
        for (int i = 0; i < 26 - 1; i++) {
            if (ptposes[i].empty()) continue;
            for (int j = i + 1; j < 26; j++) {
                if (ptposes[j].empty()) continue;
                auto start1 = starts[ptposes[i][0]];
                auto start2 = starts[ptposes[j][0]];
                bool equal = true;
                while (start1 < ssize && start2 < ssize && s[start1] != ' ' && s[start2] != ' ') {
                    if (s[start1] != s[start2]) {
                        equal = false;
                        break;
                    }
                    ++start1, ++start2;
                }
                if (equal && (s[start1] != ' ' || s[start2] != ' ')) equal = false;
                if (equal) return false;
            }
        }

        return true;
    }
};

void test(string pattern, string s, bool expect) {
    save4print(pattern);
    save4print(s);
    Solution so;
    auto ret = so.wordPattern(pattern, s);
    assert_eq_ret(expect, ret);
}

int main() {
    test("jquery", "jquery", false);
    test("abba", "dog dog dog dog", false);  // 这里还要check互相不相等。。。
    test("abba", "dog cat cat dog", true);
    test("abba", "dog cat cat fish", false);
    test("aaaa", "dog cat cat dog", false);

    return 0;
}
