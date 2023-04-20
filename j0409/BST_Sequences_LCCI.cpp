#include "../inc.h"


class Solution {
    vector<vector<int>> ret;

   public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if (root == nullptr) return ret;
        queue<TreeNode*> q;
        vector<int> path;
        path.push_back(root->val);
        helper(root, q, path);
        return ret;
    }
    void helper(TreeNode* curr, queue<TreeNode*> q, vector<int>& path) {
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
        if (q.empty()) {
            ret.push_back(path);
            return;
        }
        auto qsize = q.size();
        for (size_t i = 0; i < qsize; ++i) {
            TreeNode* n = q.front();
            q.pop();
            path.push_back(n->val);
            helper(n, q, path);
            path.pop_back();
            q.push(n);
        }
    }
};

void test(const vector<ComplexVal>& vals, vector<vector<int>>&& expect) {
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);

    Solution so;
    auto ret = so.BSTSequences(root);
    auto ret_bk = ret;
    std::sort(ret.begin(), ret.end());
    std::sort(expect.begin(), expect.end());
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vals);
        print(expect);
        print(ret_bk);
        print(ret);
        print();
    }
}

int main() {
    test({2, 1, 3}, {{2, 1, 3}, {2, 3, 1}});
    test({4, 2, 6, 1, 3, 5, 7},
         {{4, 2, 6, 1, 3, 5, 7}, {4, 2, 6, 1, 3, 7, 5}, {4, 2, 6, 1, 5, 7, 3}, {4, 2, 6, 1, 5, 3, 7},
          {4, 2, 6, 1, 7, 3, 5}, {4, 2, 6, 1, 7, 5, 3}, {4, 2, 6, 3, 5, 7, 1}, {4, 2, 6, 3, 5, 1, 7},
          {4, 2, 6, 3, 7, 1, 5}, {4, 2, 6, 3, 7, 5, 1}, {4, 2, 6, 3, 1, 5, 7}, {4, 2, 6, 3, 1, 7, 5},
          {4, 2, 6, 5, 7, 1, 3}, {4, 2, 6, 5, 7, 3, 1}, {4, 2, 6, 5, 1, 3, 7}, {4, 2, 6, 5, 1, 7, 3},
          {4, 2, 6, 5, 3, 7, 1}, {4, 2, 6, 5, 3, 1, 7}, {4, 2, 6, 7, 1, 3, 5}, {4, 2, 6, 7, 1, 5, 3},
          {4, 2, 6, 7, 3, 5, 1}, {4, 2, 6, 7, 3, 1, 5}, {4, 2, 6, 7, 5, 1, 3}, {4, 2, 6, 7, 5, 3, 1},
          {4, 2, 1, 3, 6, 5, 7}, {4, 2, 1, 3, 6, 7, 5}, {4, 2, 1, 6, 3, 5, 7}, {4, 2, 1, 6, 3, 7, 5},
          {4, 2, 1, 6, 5, 7, 3}, {4, 2, 1, 6, 5, 3, 7}, {4, 2, 1, 6, 7, 3, 5}, {4, 2, 1, 6, 7, 5, 3},
          {4, 2, 3, 6, 1, 5, 7}, {4, 2, 3, 6, 1, 7, 5}, {4, 2, 3, 6, 5, 7, 1}, {4, 2, 3, 6, 5, 1, 7},
          {4, 2, 3, 6, 7, 1, 5}, {4, 2, 3, 6, 7, 5, 1}, {4, 2, 3, 1, 6, 5, 7}, {4, 2, 3, 1, 6, 7, 5},
          {4, 6, 2, 5, 7, 1, 3}, {4, 6, 2, 5, 7, 3, 1}, {4, 6, 2, 5, 1, 3, 7}, {4, 6, 2, 5, 1, 7, 3},
          {4, 6, 2, 5, 3, 7, 1}, {4, 6, 2, 5, 3, 1, 7}, {4, 6, 2, 7, 1, 3, 5}, {4, 6, 2, 7, 1, 5, 3},
          {4, 6, 2, 7, 3, 5, 1}, {4, 6, 2, 7, 3, 1, 5}, {4, 6, 2, 7, 5, 1, 3}, {4, 6, 2, 7, 5, 3, 1},
          {4, 6, 2, 1, 3, 5, 7}, {4, 6, 2, 1, 3, 7, 5}, {4, 6, 2, 1, 5, 7, 3}, {4, 6, 2, 1, 5, 3, 7},
          {4, 6, 2, 1, 7, 3, 5}, {4, 6, 2, 1, 7, 5, 3}, {4, 6, 2, 3, 5, 7, 1}, {4, 6, 2, 3, 5, 1, 7},
          {4, 6, 2, 3, 7, 1, 5}, {4, 6, 2, 3, 7, 5, 1}, {4, 6, 2, 3, 1, 5, 7}, {4, 6, 2, 3, 1, 7, 5},
          {4, 6, 5, 7, 2, 1, 3}, {4, 6, 5, 7, 2, 3, 1}, {4, 6, 5, 2, 7, 1, 3}, {4, 6, 5, 2, 7, 3, 1},
          {4, 6, 5, 2, 1, 3, 7}, {4, 6, 5, 2, 1, 7, 3}, {4, 6, 5, 2, 3, 7, 1}, {4, 6, 5, 2, 3, 1, 7},
          {4, 6, 7, 2, 5, 1, 3}, {4, 6, 7, 2, 5, 3, 1}, {4, 6, 7, 2, 1, 3, 5}, {4, 6, 7, 2, 1, 5, 3},
          {4, 6, 7, 2, 3, 5, 1}, {4, 6, 7, 2, 3, 1, 5}, {4, 6, 7, 5, 2, 1, 3}, {4, 6, 7, 5, 2, 3, 1}});
    return 0;
}
