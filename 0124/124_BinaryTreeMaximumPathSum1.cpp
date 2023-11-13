#include "../inc.h"

/*
记题解为f(root)
记必经过某节点且以该节点为根的最大值为rootsum(root)
记以root为根且一定包含root向下任意方向单向链最大为rootmax(root)
rootsum(root) = 下面几个的最大值：
                root->val
                root->val + rootmax(root->left)
                root->val + rootmax(root->right)
                root->val + rootmax(root->left) + rootmax(root->Right)
f(root) = 下面几个的最大值：
          rootsum(root)
          f(root->left)
          f(root->right)
rootmax(root) =
                root->val
                root->val + rootmax(root->left)
                root->val + rootmax(root->right)
*/
class Solution {
   public:
    int rootmax(TreeNode* root) {
        int ret = root->val;
        if (root->left) ret = max(ret, root->val + rootmax(root->left));
        if (root->right) ret = max(ret, root->val + rootmax(root->right));
        return ret;
    }
    int rootsum(TreeNode* root) {
        int ret = root->val, sum3 = ret;
        if (root->left) {
            int rmax = rootmax(root->left);
            ret = max(ret, root->val + rmax);
            sum3 += rmax;
        }
        if (root->right) {
            int rmax = rootmax(root->right);
            ret = max(ret, root->val + rmax);
            sum3 += rmax;
        }
        return max(ret, sum3);
    }
    int maxPathSum(TreeNode* root) {
        int ret = rootsum(root);
        if (root->left) ret = max(ret, maxPathSum(root->left));
        if (root->right) ret = max(ret, maxPathSum(root->right));
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    save4print(vals);
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().maxPathSum(root));
}

int main() {
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1}, 48);
    test({2, -1, -2}, 2);
    test({1, -2, -3, 1, 3, -2, null, -1}, 3);
    test({-3}, -3);
    test({1, 2, 3}, 6);
    test({-10, 9, 20, null, null, 15, 7}, 42);
    return 0;
}