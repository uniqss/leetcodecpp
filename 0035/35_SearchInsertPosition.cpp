#include "../inc.h"

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {}
};

void test(vector<int>&& nums, int target, int expect) {
    Solution so;
    auto ret = so.searchInsert(nums, target);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums);
        print(target);
        print(expect);
        print(ret);
    }
}

int main() {
    test({1, 3, 5, 6}, 5, 2);
    test({1, 3, 5, 6}, 2, 1);
    test({1, 3, 5, 6}, 7, 4);
    test({1, 3, 5, 6}, 0, 0);

    return 0;
}
