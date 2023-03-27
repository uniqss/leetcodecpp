#include "../inc.h"

class Solution {
   public:
    bool isBalanced(TreeNode* root) { return helper(root, 0) >= 0; }
    int helper(TreeNode* root, int depth) {
        if (depth < 0) return -1;
        if (root == nullptr) return depth;
        int dleft = helper(root->left, depth + 1);
        if (dleft < 0) return -1;
        int dright = helper(root->right, depth + 1);
        if (dright < 0) return -1;
        return abs(dleft - dright) <= 1 ? max(dleft, dright) : -1;
    }
};

void test(const vector<ComplexVal>& vals, bool expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.isBalanced(root);
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
    test({3, 9, 20, null, null, 15, 7}, true);
    test({1, 2, 2, 3, 3, null, null, 4, 4}, false);
    return 0;
}
