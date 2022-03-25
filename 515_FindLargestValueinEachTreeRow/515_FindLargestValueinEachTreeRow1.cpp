#include "../inc.h"

class Solution {
   public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int largest = INT_MIN;
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                largest = max(largest, root->val);
                if (root->left != nullptr) q.emplace(root->left);
                if (root->right != nullptr) q.emplace(root->right);
            }
            ret.emplace_back(largest);
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, const vector<int>& expect) {
    Solution so;
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = so.largestValues(root);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        pvraw(expect);
        pvraw(ret);
        pnewline();
    }
}

int main() {
    test({1, 3, 2, 5, 3, null, 9}, {1, 3, 9});
    test({1, 2, 3}, {1, 3});
    return 0;
}
