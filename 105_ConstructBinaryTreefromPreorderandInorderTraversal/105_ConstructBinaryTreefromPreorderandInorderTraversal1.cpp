#include "../inc.h"

// 自己figure out
class Solution {
   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) { return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size()); }
    TreeNode *helper(vector<int> &preorder, size_t pstart, size_t pend, vector<int> &inorder, size_t istart, size_t iend) {
        if (pend <= pstart || iend <= istart) return nullptr;
        int vcurr = preorder[pstart];
        size_t idx_inorder = istart;
        for (; idx_inorder < iend; ++idx_inorder) {
            if (inorder[idx_inorder] == vcurr) break;
        }

        TreeNode *curr = new TreeNode(preorder[pstart]);
        curr->left = helper(preorder, pstart + 1, pstart + 1 + idx_inorder - istart, inorder, istart, idx_inorder);
        curr->right = helper(preorder, pend - (iend - idx_inorder - 1), pend, inorder, idx_inorder + 1, iend);
        return curr;
    }
};

void test(vector<int> &&preorder, vector<int> &&inorder, vector<ComplexVal> &&expect) {
    Solution so;
    TreeNode *ret = so.buildTree(preorder, inorder);
    TreeAutoReleaser _(ret);
    TreeNode *expect_tree = constructIntTree(expect);
    TreeAutoReleaser _etree(expect_tree);
    vector<int> vret;
    vector<int> vexpect;
    treeToIntVecLevelOrder(ret, vret);
    treeToIntVecLevelOrder(expect_tree, vexpect);
    if (vret == vexpect) {
        print("ok.");
    } else {
        print("not ok.");
        print(preorder);
        print(inorder);
        print(expect);
        pTree(expect_tree);
        pTree(ret);
    }
}

int main() {
    test({1, 2, 3}, {2, 3, 1}, {1, 2, null, null, 3});
    test({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7}, {3, 9, 20, null, null, 15, 7});
    test({-1}, {-1}, {-1});
    test({4, 2, 1, 3, 6, 5, 7}, {1, 2, 3, 4, 5, 6, 7}, {4, 2, 6, 1, 3, 5, 7});
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
