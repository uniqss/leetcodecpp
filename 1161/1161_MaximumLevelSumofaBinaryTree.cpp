#include "../inc.h"

class Solution {
   public:
    int maxLevelSum(TreeNode* root) {
        int64_t smax = INT64_MIN, curr;
        int ret = 0, level = 0;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            auto qsize = q.size();
            ++level;
            curr = 0;
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                curr += root->val;
                if (root->left) q.emplace(root->left);
                if (root->right) q.emplace(root->right);
            }
            if (curr > smax) {
                smax = curr;
                ret = level;
            }
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.maxLevelSum(root);
    assert_eq_ret(expect, ret);
    print(vals);
}

int main() {
    test({1, 7, 0, 7, -8, null, null}, 2);
    test({989, null, 10250, 98693, -89388, null, null, null, -32127}, 2);
    return 0;
}
