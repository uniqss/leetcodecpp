#include "../inc.h"

// 对dfs的优化  这样剪枝如果左子树比较少，性能会有显著提升，越左越明显，但仍然没有bfs性能高
class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<pair<TreeNode*, int>> stk;
        int ret = INT_MAX;
        int depth = 1;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push({root, depth});
                root = root->left;
                ++depth;
                // 剪枝策略1：向下延伸最多不超过已经探测过的最小深度
                if (depth >= ret) break;
            }
            root = stk.top().first;
            depth = stk.top().second;
            stk.pop();

            if (root->left == nullptr && root->right == nullptr) ret = min(ret, depth);

            root = root->right;
            if (root != nullptr) ++depth;
            // 剪枝策略2：向右子树扩展时，如已超过最小探测深度，剪掉整个右子树
            if (depth >= ret) root = nullptr;
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
    test({1, 2, 3, 4, 5}, 2);
    test({}, 0);
    return 0;
}

/*
[3,9,20,null,null,15,7]
[2,null,3,null,4,null,5,null,6]
*/
