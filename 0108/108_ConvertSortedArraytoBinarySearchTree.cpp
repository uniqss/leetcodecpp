#include "../inc.h"

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {}
};

void test(vector<int>&& nums, const vector<ComplexVal>& expect) {
    save4print(nums, expect);
    auto p1 = nums;
    auto ret = Solution().sortedArrayToBST(nums);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retvals;
    treeToComplexValLevelOrder(ret, retvals);
    vector<int> retvalsi;
    vcomplexFilterInt(retvals, retvalsi);
    sort(retvalsi.begin(), retvalsi.end());
    bool isbst = treeIsBST(ret);
    assert_retnone(p1 == retvalsi && isbst);
}

int main() {
    test({-10, -3, 0, 5, 9}, {0, -3, 9, -10, null, 5});
    test({1, 3}, {3, 1});
    return 0;
}
