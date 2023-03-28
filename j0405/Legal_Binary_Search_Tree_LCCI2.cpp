#include "../inc.h"

class Solution {
   public:
    bool isValidBST(TreeNode* root) { return helper(root, INT64_MIN, INT64_MAX); }
    bool helper(TreeNode* root, int64_t vmin, int64_t vmax) {
        if (root == nullptr) return true;
        if (root->val <= vmin || root->val >= vmax) return false;
        return helper(root->left, vmin, root->val) && helper(root->right, root->val, vmax);
    }
};

void test(const vector<ComplexVal>& vals, bool expect) {
    TreeNode* root = constructIntTree(vals);
    Solution so;
    auto ret = so.isValidBST(root);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vals);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({2147483647}, true);
    test({1, 1}, false);
    test({2, 1, 3}, true);
    test({5, 1, 4, null, null, 3, 6}, false);
    return 0;
}
