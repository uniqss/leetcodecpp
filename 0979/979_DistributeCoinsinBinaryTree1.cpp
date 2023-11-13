#include "../inc.h"

class Solution {
    int ret = 0;

   public:
    int distributeCoins(TreeNode* root) {
        ret = 0;
        dfs(root);
        return ret;
    }
    // dfs 的意义：返回root为根节点的整棵树的总的多出来的coin
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        // ret的意义：左子树需要移动的次数+右子树需要移动的coin次数，无视根节点，就正好是总的需要移动的次数
        // ret += abs(l) + abs(r);
        // ret的意义：根节点总共需要往左右子节点移动的总数量，遍历所有根节点，也正好就是总的需要移动的次数
        ret += abs(l + r + root->val - 1);
        return l + r + root->val - 1;
    }
};

void test(const vector<int>& vals, int expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.distributeCoins(root);
    assert_eq_ret(expect, ret);
    print(vals);
}

int main() {
    test({3, 0, 0}, 2);
    test({0, 3, 0}, 3);
    return 0;
}
