#include "../inc.h"

// 对1的性能优化， 采用中文官方解法里面的hash来存储一下避免多次在数组里找
class Solution {
    unordered_map<int, size_t> mapInorderIdx_;

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (size_t i = 0; i < inorder.size(); ++i) {
            mapInorderIdx_[inorder[i]] = i;
        }

        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode *helper(vector<int> &preorder, size_t pstart, size_t pend, vector<int> &inorder, size_t istart, size_t iend) {
        if (pend <= pstart || iend <= istart) return nullptr;
        int vcurr = preorder[pstart];
        size_t idx_inorder = mapInorderIdx_[vcurr];

        TreeNode *curr = new TreeNode(preorder[pstart]);
        curr->left = helper(preorder, pstart + 1, pstart + 1 + idx_inorder - istart, inorder, istart, idx_inorder);
        curr->right = helper(preorder, pend - (iend - idx_inorder - 1), pend, inorder, idx_inorder + 1, iend);
        return curr;
    }
};

void test(vector<int> &&preorder, vector<int> &&inorder, vector<ComplexVal> &&expect) {
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
