#include "../inc.h"

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {}
};

void test(vector<int>&& preorder, vector<int>&& inorder, vector<ComplexVal>&& expect) {
    save4print(preorder, inorder);
    TreeNode* ret = Solution().buildTree(preorder, inorder);
    TreeNode* expect_tree = constructIntTree(expect);
    TreeAutoReleaser _2(ret, expect_tree);
    vector<int> vret, vexpect;
    treeToIntVecLevelOrder(ret, vret);
    treeToIntVecLevelOrder(expect_tree, vexpect);
    assert_eq_ret(vexpect, vret);
}

int main() {
    test({4, 2, 1, 3, 6, 5, 7}, {1, 2, 3, 4, 5, 6, 7}, {4, 2, 6, 1, 3, 5, 7});
    test({1, 2, 3}, {2, 3, 1}, {1, 2, null, null, 3});
    test({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7}, {3, 9, 20, null, null, 15, 7});
    test({-1}, {-1}, {-1});
    return 0;
}

/*
[1,2,3]
[2,3,1]
[1,2,null,null,3]


[3,9,20,15,7]
[9,3,15,20,7]
[-1]
[-1]

[3,9,20,null,null,15,7]
[-1]
*/
