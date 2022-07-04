#include "../inc.h"

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int sum = 0;
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front().first;
                sum = q.front().second;
                q.pop();
                if (root->left == nullptr && root->right == nullptr) {
                    if (sum + root->val == targetSum) return true;
                    continue;
                }
                sum += root->val;
                if (root->left) q.push({root->left, sum});
                if (root->right) q.push({root->right, sum});
            }
        }
        return false;
    }
};

void test(const vector<ComplexVal>& vals, int targetsum, bool expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.hasPathSum(root, targetsum);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        praw(targetsum);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test({1, 2}, 1, false);
    test({}, 0, false);
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1}, 22, true);
    test({1, 2, 3}, 5, false);

    return 0;
}
