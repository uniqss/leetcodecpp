#include "../inc.h"

class Solution {
   public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {}
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
