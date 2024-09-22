#include "../inc.h"

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        int n = strs.size();
        for (int i = 0; i < 200; ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

void test(vector<string>&& strs, string expect) {
    save4print(strs);
    assert_eq_ret(expect, Solution().longestCommonPrefix(strs));
}

int main() {
    test({"flower", "flow", "flight"}, "fl");
    test({"a"}, "a");
    test({"flower", "flow", "flight"}, "fl");
    test({"dog", "racecar", "car"}, "");
    return 0;
}
