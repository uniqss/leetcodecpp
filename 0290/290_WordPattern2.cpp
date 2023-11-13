#include "../inc.h"

class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        if (pattern.size() > s.size()) return false;
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        s.push_back(' ');
        int start = 0, ssize = s.size(), pidx = 0, psize = pattern.size();
        for (int i = 0; i < ssize; ++i) {
            if (s[i] == ' ') {
                string scurr = s.substr(start, i - start);
                char pcurr = pattern[pidx];
                if (p2s.count(pcurr) > 0 && p2s[pcurr] != scurr) return false;
                if (s2p.count(scurr) > 0 && s2p[scurr] != pcurr) return false;
                s2p[scurr] = pcurr;
                p2s[pcurr] = scurr;
                ++pidx;
                if (pidx >= psize && i < ssize - 1) return false;
                start = i + 1;
            }
        }
        return pidx == psize;
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
