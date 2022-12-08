#include "../inc.h"

// recursive 明明 两行代码我写成了五六行。。。
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
    int helper(TreeNode* node, int depth) {
        if (node == nullptr) return depth;
        return max(helper(node->left, depth + 1), helper(node->right, depth + 1));
    }
};

void test(const vector<ComplexVal>& vals, int expected) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);

    Solution so;
    auto ret = so.maxDepth(root);
    if (expected == ret) {
        print("ok.");
    } else {
        print("not ok.");
        print(vals);
        print(expected);
        print(ret);
    }
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, 3);
    test({1, null, 2}, 2);
    test({}, 0);

    return 0;
}

/*
[3,9,20,null,null,15,7]
[1,null,2]
3
2
*/
