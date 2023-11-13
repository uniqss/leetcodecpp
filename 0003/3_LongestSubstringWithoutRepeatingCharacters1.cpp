#include "../inc.h"

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> dict(256);
        queue<char> q;
        int ret = 0, curr = 0;
        for (char c : s) {
            while (!q.empty() && dict[c]) {
                auto qc = q.front();
                q.pop();
                dict[qc] = false;
                --curr;
            }
            ++curr;
            dict[c] = true;
            q.emplace(c);
            ret = max(ret, curr);
        }
        return ret;
    }
};

void test(string s, int expect) {
    save4print(s);
    Solution so;
    auto ret = so.lengthOfLongestSubstring(s);
    assert_eq_ret(expect, ret);
}

int main() {
    test("abcabcbb", 3);
    test("bbbbb", 1);
    test("pwwkew", 3);
    return 0;
}
