#include "../stl.h"

// threaded binary tree
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        while (curr != nullptr) {
            
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    Solution so;
    TreeNode* tree = constructIntTree(root);
    vector<TreeNode*> allNodes;
    treeToVector(tree, allNodes);

    auto ret = so.postorderTraversal(tree);
    if (ret != expect) {
        praw("## not ok.");
        pvcomplex(root);
        pvraw(expect);
        pvraw(ret);
    } else {
        praw("ok.");
    }

    releaseAllTreeNodes(allNodes);
}

int main() {
    test({1, null, 2, 3}, {3, 2, 1});
    test({}, {});
    test({1}, {1});

    test({4, 2, 6, 1, 3, 5, 7}, {1, 3, 2, 5, 7, 6, 4});
    return 0;
}
