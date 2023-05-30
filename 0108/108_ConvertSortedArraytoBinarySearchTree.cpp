#include "../inc.h"

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {}
};

void test(vector<int>&& nums, const vector<ComplexVal>& expect) {
    Solution so;
    auto nums_param = nums;
    auto ret = so.sortedArrayToBST(nums);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retvals;
    treeToComplexValLevelOrder(ret, retvals);
    if (retvals == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(nums);
        print(expect);
        print(ret);
    }
}

int main() {
    test({-10, -3, 0, 5, 9}, {0, -3, 9, -10, null, 5});
    test({1, 3}, {3, 1});
    return 0;
}
