#include "../inc.h"

// stack 对2的优化，这个写法太经典！
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*> stk;
        vector<int> ret;
        while (curr != nullptr || !stk.empty()) {
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            ret.push_back(curr->val);
            curr = curr->right;
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    save4print(root);
    TreeNode* tree = constructIntTree(root);
    TreeAutoReleaser _(tree);
    assert_eq_ret(expect, Solution().inorderTraversal(tree));
}

int main() {
    test({4, 2, 6, 1, 3, 5, 7}, {1, 2, 3, 4, 5, 6, 7});
    test({1, null, 2, 3}, {1, 3, 2});
    test({}, {});
    test({1}, {1});
    return 0;
}
