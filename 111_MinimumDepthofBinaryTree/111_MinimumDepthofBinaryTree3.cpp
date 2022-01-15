#include "../stl.h"

// dfs
class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int ret = INT_MAX;
        stack<pair<TreeNode*, int>> stk;
        int depth = 1;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push({root, depth});
                root = root->left;
                ++depth;
            }
            root = stk.top().first;
            depth = stk.top().second;
            stk.pop();

            if (root->left == nullptr && root->right == nullptr) ret = min(ret, depth);

            root = root->right;
            if (root != nullptr) ++depth;
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);

    Solution so;
    auto ret = so.minDepth(root);
    if (ret != expect) {
        praw("not ok.");
        pvcomplex(vals);
        praw(expect);
        praw(ret);
    } else {
        praw("ok.");
    }
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, 2);
    test({2, null, 3, null, 4, null, 5, null, 6}, 5);
    test({}, 0);
    return 0;
}

/*
[3,9,20,null,null,15,7]
[2,null,3,null,4,null,5,null,6]
*/
