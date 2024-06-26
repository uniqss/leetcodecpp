#include "../inc.h"

class Solution {
   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        auto ret = helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
        return ret;
    }
    TreeNode* helper(const vector<int>& inorder, int ibegin, int iend, const vector<int>& postorder, int pbegin, int pend) {
        if (pbegin >= pend) return nullptr;
        TreeNode* root = new TreeNode(postorder[pend - 1]);

        if (pbegin + 1 == pend) return root;

        int imid = 0;
        for (imid = ibegin; imid < iend; ++imid) {
            if (inorder[imid] == root->val) break;
        }
        root->left = helper(inorder, ibegin, imid, postorder, pbegin, pbegin + imid - ibegin);
        root->right = helper(inorder, imid + 1, iend, postorder, pbegin + imid - ibegin, pend - 1);
        return root;
    }
};

void test(vector<int>&& inorder, vector<int>&& postorder, const vector<ComplexVal>& expect) {
    save4print(inorder);
    save4print(postorder);
    Solution so;
    auto ret = so.buildTree(inorder, postorder);
    auto etree = constructIntTree(expect);
    TreeAutoReleaser _(ret, etree);
    vector<int> ret_vec;
    treeToIntVecLevelOrder(ret, ret_vec);
    vector<int> expect_vec;
    treeToIntVecLevelOrder(etree, expect_vec);
    assert_eq_ret(expect_vec, ret_vec);
}

int main() {
    test({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3}, {3, 9, 20, null, null, 15, 7});
    test({-1}, {-1}, {-1});
    return 0;
}