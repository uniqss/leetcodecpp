#include "../inc.h"

class Solution {
   public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
            if (lower == upper) {
                return {std::to_string(lower)};
            } else {
                return {std::to_string(lower) + "->" + std::to_string(upper)};
            }
        }
        vector<string> ret;
        if (nums[0] != INT_MIN) nums.insert(nums.begin(), INT_MIN);
        if (nums[nums.size() - 1] != INT_MAX) nums.push_back(INT_MAX);
        for (int i = 1; i < nums.size(); i++) {
            int l = nums[i - 1], u = nums[i];
            if (lower >= u) continue;
            if (upper <= l) break;
            l = max(l + 1, lower);
            u = min(u - 1, upper);
            if (l == u) {
                ret.push_back(std::to_string(l));
            } else if (l < u) {
                ret.push_back(std::to_string(l) + "->" + std::to_string(u));
            }
        }

        return ret;
    }
};

void test(vector<int>&& nums, int lower, int upper, const vector<string>& expect) {
    Solution so;
    auto ret = so.findMissingRanges(nums, lower, upper);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(nums);
        print(lower);
        print(upper);
        print(expect);
        print(ret);
    }
}

int main() {
    test({0, 1, 3, 50, 75}, 0, 99, {"2", "4->49", "51->74", "76->99"});
    test({0, 1, 2, 3, 7}, 0, 7, {"4->6"});
    test({2147483647}, 0, 2147483647, {"0->2147483646"});
    test({}, -2147483648, 2147483647, {"-2147483648->2147483647"});
    test({}, 1, 1, {"1"});
    return 0;
}
