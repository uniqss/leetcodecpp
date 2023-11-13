#include "../inc.h"

class Solution {
   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<bool> sp(s.size() - 1);
        backtrack(s, sp, 0, ret);
        return ret;
    }
    void backtrack(const string& s, vector<bool>& sp, int idx, vector<vector<string>>& ret) {
        if (idx == sp.size()) {
            int sppre = idx - 1;
            while (sppre >= 0 && !sp[sppre]) --sppre;
            if (check(s, sppre + 1, s.size() - 1)) {
                int begin = 0;
                vector<string> curr;
                sp.emplace_back(true);
                for (int i = 0; i < sp.size(); ++i) {
                    if (sp[i]) {
                        curr.emplace_back(s.substr(begin, i + 1 - begin));
                        begin = i + 1;
                    }
                }
                sp.pop_back();
                ret.emplace_back(curr);
            }
            return;
        }
        backtrack(s, sp, idx + 1, ret);
        int sppre = idx - 1;
        while (sppre >= 0 && !sp[sppre]) --sppre;
        if (check(s, sppre + 1, idx)) {
            sp[idx] = true;
            backtrack(s, sp, idx + 1, ret);
            sp[idx] = false;
        }
    }
    // []
    bool check(const string& s, int begin, int end) {
        while (begin < end) {
            if (s[begin] != s[end]) return false;
            ++begin, --end;
        }
        return true;
    }
};

void test(string s, vector<vector<string>>&& expect) {
    save4print(s);
    sort(expect.begin(), expect.end());
    auto ret = Solution().partition(s);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test("aab", {{"a", "a", "b"}, {"aa", "b"}});
    test("a", {{"a"}});
    return 0;
}