#include "../inc.h"

// stack 这个写法很经典，但不太好想出来，有点往回退着走路的感觉
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ret;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            ret.push_back(curr->val);
            if (curr->right != nullptr) stk.push(curr->right);
            if (curr->left != nullptr) stk.push(curr->left);
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    TreeNode* tree = constructIntTree(root);
    TreeAutoReleaser _(tree);
    assert_eq_ret(expect, Solution().preorderTraversal(tree));
}

int main() {
    test({1, 4, 3, 2}, {1, 4, 2, 3});
    test({1, null, 2, 3}, {1, 2, 3});
    test({}, {});
    test({1}, {1});

    test({4, 2, 6, 1, 3, 5, 7}, {4, 2, 1, 3, 6, 5, 7});

    return 0;
}
