#include "../inc/inc.h"

// recursive
class Solution {
   public:
    bool isValidBST(TreeNode* root) { return helper(root, INT64_MIN, INT64_MAX); }
    bool helper(TreeNode* node, int64_t vmin, int64_t vmax) {
        if (node == nullptr) return true;
        if (node->val <= vmin) return false;
        if (node->val >= vmax) return false;
        if (!helper(node->left, vmin, node->val)) return false;
        if (!helper(node->right, node->val, vmax)) return false;
        return true;
    }
};

void test(const vector<ComplexVal>& vals, bool expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);

    Solution so;
    bool ret = so.isValidBST(root);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok");
        print(vals);
        print(expect);
        print(ret);
    }
}

int main() {
    test({2, 1, 3}, true);
    test({5, 1, 4, null, null, 3, 6}, false);
    return 0;
}

/*
[2,1,3]
[5,1,4,null,null,3,6]
true
false
*/
