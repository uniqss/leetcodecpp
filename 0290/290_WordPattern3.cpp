#include "../inc.h"

class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        int psize = pattern.size(), ssize = s.size(), pi = 0;
        size_t start = 0;
        unordered_map<string, char> dict;
        unordered_set<char> used;
        for (int i = 0; i <= ssize; ++i) {
            if (s[i] == ' ' || i == ssize) {
                string curr = s.substr(start, i - start);
                auto it = dict.find(curr);
                if (it != dict.end()) {
                    if (it->second != pattern[pi]) return false;
                } else {
                    if (used.count(pattern[pi]) > 0) return false;
                    used.insert(pattern[pi]);
                    dict[curr] = pattern[pi];
                }
                ++pi;
                start = i + 1;
            }
        }
        return pi == psize;
    }
};

void test(string pattern, string s, bool expect) {
    save4print(pattern, s);
    assert_eq_ret(expect, Solution().wordPattern(pattern, s));
}

int main() {
    test("jquery", "jquery", false);
    test("abba", "dog dog dog dog", false);  // 这里还要check互相不相等。。。
    test("abba", "dog cat cat dog", true);
    test("abba", "dog cat cat fish", false);
    test("aaaa", "dog cat cat dog", false);

    return 0;
}
