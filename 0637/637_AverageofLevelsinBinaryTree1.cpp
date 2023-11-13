#include "../inc.h"

class Solution {
   public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> q;
        if (root != nullptr) q.emplace(root);
        while (!q.empty()) {
            int qsize = q.size();
            int64_t sum = 0;
            for (int i = 0; i < qsize; ++i) {
                root = q.front(), q.pop();
                sum += root->val;
                if (root->left) q.emplace(root->left);
                if (root->right) q.emplace(root->right);
            }
            ret.emplace_back((double)sum / qsize);
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& vals, const vector<double>& expect) {
    save4print(vals);
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.averageOfLevels(root);
    assert_eq_ret(expect, ret);
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, {3.00000, 14.50000, 11.00000});
    test({3, 9, 20, 15, 7}, {3.00000, 14.50000, 11.00000});

    return 0;
}