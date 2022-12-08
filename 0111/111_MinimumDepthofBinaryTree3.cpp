#include "../inc.h"

// dfs 这一题不建议用dfs，如果这棵树足够倾斜，比如右边第一个子节点就是叶节点，而左子树非常壮大，则性能会差很多倍
// dfs 可否剪枝？如何剪枝？参见3.1
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
        print("not ok.");
        print(vals);
        print(expect);
        print(ret);
    } else {
        print("ok.");
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
