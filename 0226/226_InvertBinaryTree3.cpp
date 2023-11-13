#include "../inc.h"

class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr != nullptr || !stk.empty()) {
            while (curr != nullptr) {
                stk.emplace(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            TreeNode* tmp = curr;
            curr = curr->right;
            std::swap(tmp->left, tmp->right);
        }

        return root;
    }
};

void test(const vector<int>& vals, const vector<int>& expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    TreeNode* ret = so.invertTree(root);
    vector<int> ret_vec;
    treeToIntVecLevelOrder(ret, ret_vec);
    assert_eq_ret(expect, ret_vec);
}

int main() {
    test({4, 2, 7, 1, 3, 6, 9}, {4, 7, 2, 9, 6, 3, 1});
    test({2, 1, 3}, {2, 3, 1});
    test({}, {});
    return 0;
}

/*
[4,2,7,1,3,6,9]
[2,1,3]
[]
*/
