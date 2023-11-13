#include "../inc.h"

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0].empty()) return "";
        int i = 0, size0 = strs[0].size(), n = strs.size();
        if (n == 1) return strs[0];
        for (; i < size0; ++i) {
            bool valid = true;
            for (int j = 1; j < n; ++j) {
                if (strs[j][i] != strs[0][i]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        return strs[0].substr(0, i);
    }
};

void test(vector<string>&& strs, string expect) {
    save4print(strs);
    Solution so;
    auto ret = so.longestCommonPrefix(strs);
    assert_eq_ret(expect, ret);
}

int main() {
    test({"flower", "flow", "flight"}, "fl");
    test({"a"}, "a");
    test({"flower", "flow", "flight"}, "fl");
    test({"dog", "racecar", "car"}, "");
    return 0;
}
