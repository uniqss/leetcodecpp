#include "../inc.h"

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {}
};

void test(vector<int>&& nums, const vector<ComplexVal>& expect) {
    Solution so;
    auto ret = so.sortedArrayToBST(nums);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retval;
    treeToComplexValLevelOrder(ret, retval);
    if (retval == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums);
        print(expect);
        print(retval);
        print();
    }
}

int main() {
    test({-10, -3, 0, 5, 9}, {0, -3, 9, -10, null, 5});
    return 0;
}
