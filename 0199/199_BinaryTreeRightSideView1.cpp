#include "../inc.h"

class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                if (i == qsize - 1) ret.emplace_back(root->val);
                if (root->left) q.emplace(root->left);
                if (root->right) q.emplace(root->right);
            }
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& vals, const vector<int>& expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.rightSideView(root);
    assert_eq_ret(expect, ret);
    print(vals);
}

int main() {
    test({1, 2, 3, null, 5, null, 4}, {1, 3, 4});
    test({1, null, 3}, {1, 3});
    test({}, {});
    return 0;
}
