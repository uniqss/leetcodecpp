#include "../inc.h"

// recursive DFS Depth-First-Search
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
