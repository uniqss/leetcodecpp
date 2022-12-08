#include "../inc.h"

// 英文官方解法 java 版本port过来，简单一百倍，减少错误率50%+

// dfs

/*
 trick: construct every node from the beginning to the end of the preorder list
 save the inorder values to map for cache.
 */

class Solution {
    size_t preorderIdx_;
    std::unordered_map<int, int> inorderVal2Idx_;

   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        preorderIdx_ = 0;
        for (int i = 0; i < (int)inorder.size(); ++i) {
            inorderVal2Idx_[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }
    TreeNode *arrayToTree(vector<int> &preorder, int left, int right) {
        if (left > right) return nullptr;
        int currVal = preorder[preorderIdx_++];
        TreeNode *curr = new TreeNode(currVal);
        int idxCurr = inorderVal2Idx_[currVal];
        // 只限定范围，不取下标，取下标的任务交给 preorderIdx_ 而随着这样递归，正好就是dfs的前序遍历，所以 preorderIdx_ 可以工作
        curr->left = arrayToTree(preorder, left, idxCurr - 1);
        curr->right = arrayToTree(preorder, idxCurr + 1, right);
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
        print(expect_tree);
        print(ret);
    }
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
