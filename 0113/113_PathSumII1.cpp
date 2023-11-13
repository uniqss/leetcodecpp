#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        helper(root, 0, {}, targetSum, ret);
        return ret;
    }
    void helper(TreeNode* root, int sum, vector<int> path, int target, vector<vector<int>>& ret) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum + root->val == target) {
                path.push_back(root->val);
                ret.emplace_back(path);
            }
            return;
        }
        sum += root->val;
        if (root->left != nullptr) {
            path.push_back(root->val);
            helper(root->left, sum, path, target, ret);
            path.pop_back();
        }
        if (root->right != nullptr) {
            path.push_back(root->val);
            helper(root->right, sum, path, target, ret);
            path.pop_back();
        }
    }
};

void test(const vector<ComplexVal>& vals, int targetsum, vector<vector<int>>&& expect) {
    save4print(vals, targetsum);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = Solution().pathSum(root, targetsum);
    sortvvrawInnerAndOuter(expect, ret);
    assert_eq_ret(expect, ret);
}

int main() {
    test({}, 0, {});
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1}, 22, {{5, 4, 11, 2}, {5, 8, 4, 5}});
    test({1, 2, 3}, 5, {});

    return 0;
}
