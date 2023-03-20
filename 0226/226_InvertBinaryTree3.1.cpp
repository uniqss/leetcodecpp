#include "../inc/inc.h"

class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr != nullptr || !stk.empty()) {
            while (curr != nullptr) {
                stk.emplace(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            TreeNode* tmp = curr->left;
            curr->left = curr->right;
            curr->right = tmp;

            curr = curr->left;
        }

        return root;
    }
};

void test(const vector<int>& vals, const vector<int>& expect) {
    TreeNode* root = constructIntBinaryTreeLayerOrder(vals);
    TreeAutoReleaser _(root);

    Solution so;
    TreeNode* ret = so.invertTree(root);
    vector<int> ret_vec;
    treeToIntVecLevelOrder(ret, ret_vec);
    if (ret_vec != expect) {
        print("not ok.");
        print(vals);
        print(expect);
        print(ret_vec);
    } else {
        print("ok.");
    }
}

int main() {
    test({4, 2, 6, 1, 3, 5, 7}, {4, 6, 2, 7, 5, 3, 1});
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
