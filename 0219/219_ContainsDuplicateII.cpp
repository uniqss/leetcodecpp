#include "../inc.h"

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {}
};

void test(vector<int>&& nums, int k, bool expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.containsNearbyDuplicate(nums, k);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums_param);
        print(k);
        print(expect);
        print(ret);
    }
}

int main() {
    test({1, 2, 3, 1}, 3, true);
    test({1, 0, 1, 1}, 1, true);
    test({1, 2, 3, 1, 2, 3}, 2, false);
    return 0;
}
