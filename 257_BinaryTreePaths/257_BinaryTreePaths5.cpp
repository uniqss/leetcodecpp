#include "../inc.h"

/*
基本差不多，只是在backtrace之前就已经把节点的值加进去了，另外不一样的是判空的处理，这样少掉n次函数调用
*/

class Solution {
   public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == nullptr) return ret;
        helper(root, to_string(root->val), ret);
        return ret;
    }
    void helper(TreeNode* root, string path, vector<string>& ret) {
        if (root->left == nullptr && root->right == nullptr) {
            ret.emplace_back(path);
            return;
        }
        if (root->left) {
            helper(root->left, path + "->" + to_string(root->left->val), ret);
        }
        if (root->right) {
            helper(root->right, path + "->" + to_string(root->right->val), ret);
        }
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