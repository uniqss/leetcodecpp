#include "../inc.h"

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.empty()) return ret;
        int begin = nums[0];
        int end = begin;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == end + 1) {
                end = nums[i];
                continue;
            } else {
                if (begin == end) {
                    ret.push_back(std::to_string(begin));
                } else {
                    ret.push_back(std::to_string(begin) + "->" + std::to_string(end));
                }
            }
            begin = nums[i], end = begin;
        }

        if (begin == end) {
            ret.push_back(std::to_string(begin));
        } else {
            ret.push_back(std::to_string(begin) + "->" + std::to_string(end));
        }

        return ret;
    }
};

void test(vector<int>&& nums, const vector<string>& expect) {
    Solution so;
    auto ret = so.summaryRanges(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums);
        print(expect);
        print(ret);
    }
}

int main() {
    test({0, 1, 2, 4, 5, 7}, {"0->2", "4->5", "7"});
    test({0, 2, 3, 4, 6, 8, 9}, {"0", "2->4", "6", "8->9"});

    return 0;
}
