#include "../inc.h"

// 活学活用，这里比较难理解的是先right后left
// 仔细看数据我们有这样的发现：preorder的第2个一定是左子树的根。postorder的倒数第2个一定是右子树的根
// 非常有意思，具有数学上的完美的对称美
// 把这个理解透了，前序中序反拼就彻底解决了，而且这种写法，出错误的概率极低
class Solution {
    int postidx = 0;
    unordered_map<int, int> inval2idx;

   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postidx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); ++i) inval2idx[inorder[i]] = i;
        return helper(postorder, 0, postorder.size() - 1);
    }
    // []
    TreeNode* helper(const vector<int>& postorder, int inidxl, int inidxr) {
        if (postidx < 0) return nullptr;
        if (inidxl > inidxr) return nullptr;
        TreeNode* curr = new TreeNode(postorder[postidx]);
        --postidx;
        if (inidxl == inidxr) return curr;
        int inidx = inval2idx[curr->val];
        curr->right = helper(postorder, inidx + 1, inidxr);
        curr->left = helper(postorder, inidxl, inidx - 1);
        return curr;
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