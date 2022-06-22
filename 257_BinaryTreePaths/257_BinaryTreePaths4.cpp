#include "../inc.h"

class Solution {
   public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == nullptr) return ret;
        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front().first;
                string path = q.front().second;
                q.pop();
                if (root->left == nullptr && root->right == nullptr) {
                    ret.emplace_back(path);
                    continue;
                }
                if (root->left) q.push({root->left, path + "->" + to_string(root->left->val)});
                if (root->right) q.push({root->right, path + "->" + to_string(root->right->val)});
            }
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, vector<string>&& expect) {
    sort(expect.begin(), expect.end());
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.binaryTreePaths(root);
    sort(ret.begin(), ret.end());
    if (ret == expect) {
        praw("ok");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        pvraw(expect);
        pvraw(ret);
    }
}

int main() {
    test({1, 2, 3, null, 5}, {"1->2->5", "1->3"});
    test({1}, {"1"});
    return 0;
}