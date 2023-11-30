#include "../inc.h"

class Solution {
   public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stk1, stk2;
        auto next = [](TreeNode*& root, stack<TreeNode*>& stk) {
            while (root != nullptr || !stk.empty()) {
                while (root != nullptr) {
                    stk.push(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                if (root->left == nullptr && root->right == nullptr) {
                    TreeNode* ret = root;
                    root = root->right;
                    return ret;
                }
                root = root->right;
            }
            return (TreeNode*)nullptr;
        };
        TreeNode *curr1, *curr2;
        while (true) {
            curr1 = next(root1, stk1);
            curr2 = next(root2, stk2);
            if (curr1 == nullptr && curr2 == nullptr) return true;
            if (curr1 == nullptr || curr2 == nullptr) return false;
            // 看着你远走，让泪往心里流。为你，愿付出我所有
            if (curr1->val != curr2->val) return false;
        }
        return true;
    }
};

void test(const vector<ComplexVal>& v1, const vector<ComplexVal>& v2, bool expect) {
    save4print(v1, v2);
    TreeNode *root1 = constructIntTree(v1), *root2 = constructIntTree(v2);
    TreeAutoReleaser _(root1, root2);
    auto ret = Solution().leafSimilar(root1, root2);
    assert_eq_ret(expect, ret);
}

int main() {
    test({3, 5, 1, 6, 2, 9, 8, null, null, 7, 4}, {3, 5, 1, 6, 7, 4, 2, null, null, null, null, null, null, 9, 8},
         true);
    test({1, 2, 3}, {1, 3, 2}, false);
    return 0;
}
