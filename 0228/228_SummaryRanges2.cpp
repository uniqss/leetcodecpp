#include "../inc.h"

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<pair<int, int>> dict;
        for (int n : nums) {
            if (dict.empty() || dict.back().second != n - 1) {
                dict.emplace_back(n, n);
            } else {
                ++dict.back().second;
            }
        }
        vector<string> ret;
        for (const auto& [l, r] : dict) {
            if (l != r) {
                ret.emplace_back(to_string(l) + "->" + to_string(r));
            } else {
                ret.emplace_back(to_string(l));
            }
        }
        return ret;
    }
};

void test(vector<int>&& nums, const vector<string>& expect) {
    save4print(nums);
    Solution so;
    auto ret = so.summaryRanges(nums);
    assert_eq_ret(expect, ret);
}

int main() {
    test({0, 1, 2, 4, 5, 7}, {"0->2", "4->5", "7"});
    test({0, 2, 3, 4, 6, 8, 9}, {"0", "2->4", "6", "8->9"});

    return 0;
}
