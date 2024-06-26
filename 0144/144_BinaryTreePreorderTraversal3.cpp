#include "../inc.h"

// threaded binary tree ---- 不建议，会破坏树结构，非标准 morris 解法
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        while (curr != nullptr) {
            ret.push_back(curr->val);
            if (curr->right != nullptr) {
                if (curr->left == nullptr) {
                    curr->left = curr->right;
                    prev = curr->right;
                    curr->right = nullptr;
                } else {
                    prev = curr->left;
                    while (prev->right != nullptr) {
                        prev = prev->right;
                    }
                    prev->right = curr->right;
                    curr->right = nullptr;
                }
            }
            curr = curr->left;
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
