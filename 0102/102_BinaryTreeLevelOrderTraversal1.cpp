#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;

        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            auto qsize = q.size();
            vector<int> currLayer;
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                currLayer.emplace_back(root->val);
                if (root->left != nullptr) q.emplace(root->left);
                if (root->right != nullptr) q.emplace(root->right);
            }
            ret.emplace_back(currLayer);
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().levelOrder(root));
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, {{3}, {9, 20}, {15, 7}});
    test({1}, {{1}});
    test({}, {});
    return 0;
}
