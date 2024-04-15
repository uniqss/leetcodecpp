#include "../inc.h"

/*
time complexity: O(n)
space complexity: O(1)
*/

class Solution {
   public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        return helper(root, 0);
    }
    int helper(TreeNode* curr, int vparent) {
        int vcurr = vparent * 10 + curr->val, vl = 0, vr = 0;
        if (curr->left == nullptr && curr->right == nullptr) return vcurr;
        if (curr->left) vl = helper(curr->left, vcurr);
        if (curr->right) vr = helper(curr->right, vcurr);
        return vl + vr;
    }
};

void test(const vector<int>& vals, int expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = Solution().sumNumbers(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 2, 3}, 25);
    test({4, 9, 0, 5, 1}, 1026);
    return 0;
}
