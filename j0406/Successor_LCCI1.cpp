#include "../inc.h"

class Solution {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ret = nullptr;
        TreeNode* curr = root;
        bool foundp = false;
        stack<TreeNode*> stk;
        while (curr != nullptr || !stk.empty()) {
            if (curr == nullptr) {
                curr = stk.top();
                stk.pop();
            } else {
                while (curr->left != nullptr) {
                    stk.emplace(curr);
                    curr = curr->left;
                }
            }
            if (foundp) return curr;
            if (curr == p) {
                foundp = true;
            }
            curr = curr->right;
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& vals, int pv, ComplexVal expect) {
    save4print(vals, pv);
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto p = treeFindUniqueNodeByVal(root, pv);
    auto ret = Solution().inorderSuccessor(root, p);
    ComplexVal retval = null;
    if (ret != nullptr) retval = ret->val;
    assert_eq_ret(expect, retval);
}

int main() {
    test({2, 1, 3}, 1, 2);
    test({5, 3, 6, 2, 4, null, null, 1}, 6, null);
    return 0;
}
