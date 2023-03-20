#include "../inc/inc.h"

class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        stack<TreeNode*> stk;
        stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            ret.emplace_back(root->val);
            if (root->left != nullptr) stk.emplace(root->left);
            if (root->right != nullptr) stk.emplace(root->right);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    Solution so;
    TreeNode* tree = constructIntTree(root);
    TreeAutoReleaser _(tree);

    auto ret = so.postorderTraversal(tree);
    if (ret != expect) {
        print("## not ok.");
        print(root);
        print(expect);
        print(ret);
    } else {
        print("ok.");
    }
}

int main() {
    test({4, 2, 6, 1, 3, 5, 7}, {1, 3, 2, 5, 7, 6, 4});

    test({1, null, 2, 3}, {3, 2, 1});
    test({}, {});
    test({1}, {1});
    return 0;
}
