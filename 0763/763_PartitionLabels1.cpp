#include "../inc.h"

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        vector<int> ret;
        vector<int> pl(26, INT_MAX), pr(26, INT_MIN);
        int ssize = s.size();
        for (int i = 0; i < ssize; ++i) {
            int c = s[i] - 'a';
            pl[c] = min(pl[c], i);
            pr[c] = max(pr[c], i);
        }
        int maxpos = 0, start = 0;
        for (int i = 0; i < ssize; ++i) {
            int c = s[i] - 'a';
            maxpos = max(maxpos, pr[c]);
            if (i == maxpos) {
                ++maxpos;
                ret.emplace_back(i - start + 1);
                start = i + 1;
            }
        }
        if (start < ssize - 1) ret.emplace_back(ssize - start + 1);
        return ret;
    }
};

void test(string s, const vector<int>& expect) {
    Solution so;
    auto ret = so.partitionLabels(s);
    assert_eq_ret(expect, ret);
    print(s);
}

int main() {
    test("ababcbacadefegdehijhklij", {9, 7, 8});
    test("eccbbbbdec", {10});
    return 0;
}
