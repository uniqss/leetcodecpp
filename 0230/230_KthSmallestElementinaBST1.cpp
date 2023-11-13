#include "../inc.h"


class Solution {
   public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top(), stk.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
        return -1;
    }
};

void test(vector<ComplexVal>&& vals, int k, int expect) {
    auto p1 = vals;
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.kthSmallest(root, k);
    assert_eq_ret(expect, ret);
    print(p1, k);
}

int main() {
    test({3, 1, 4, null, 2}, 1, 1);
    test({5, 3, 6, 2, 4, null, null, 1}, 3, 3);
    return 0;
}