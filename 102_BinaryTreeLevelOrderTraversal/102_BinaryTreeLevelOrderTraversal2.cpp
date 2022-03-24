#include "../inc.h"

/*
虽然建议是bfs，但是dfs也能做，而且很精炼
*/
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        dfs(ret, 0, root);
        return ret;
    }
    void dfs(vector<vector<int>>& ret, int depth, TreeNode* root) {
        if (ret.size() <= depth) ret.resize(ret.size() + 1);
        ret[depth].emplace_back(root->val);
        if (root->left != nullptr) dfs(ret, depth + 1, root->left);
        if (root->right != nullptr) dfs(ret, depth + 1, root->right);
    }
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.levelOrder(root);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        pvvraw(expect);
        pvvraw(ret);
        pnewline();
    }
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, {{3}, {9, 20}, {15, 7}});
    test({1}, {{1}});
    test({}, {});
    return 0;
}
