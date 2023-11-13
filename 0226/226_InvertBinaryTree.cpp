#include "../inc.h"

class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {}
};

void test(const vector<int>& vals, const vector<int>& expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    TreeNode* ret = so.invertTree(root);
    vector<int> ret_vec;
    treeToIntVecLevelOrder(ret, ret_vec);
    assert_eq_ret(expect, ret_vec);
}

int main() {
    test({4, 2, 6, 1, 3, 5, 7}, {4, 6, 2, 7, 5, 3, 1});
    test({4, 2, 7, 1, 3, 6, 9}, {4, 7, 2, 9, 6, 3, 1});
    test({2, 1, 3}, {2, 3, 1});
    test({}, {});
    return 0;
}

/*
[4,2,7,1,3,6,9]
[2,1,3]
[]
*/
