#include "../inc.h"

// DFS no recursive
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<pair<TreeNode*, int>> stk;
        int depth = 1;
        int ret = 1;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push({root, depth});
                root = root->left;
                ++depth;
            }
            root = stk.top().first;
            depth = stk.top().second;
            stk.pop();

            ret = max(ret, depth);

            root = root->right;
            if (root != nullptr) ++depth;
        }
        return ret;
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
