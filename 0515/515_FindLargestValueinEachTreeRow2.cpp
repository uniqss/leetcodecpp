#include "../inc.h"

/*
这是不是应该叫backtrace更贴切？？？但是确实又是dfs
*/
class Solution {
   public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        dfs(ret, root, 0);
        return ret;
    }
    void dfs(vector<int>& ret, TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (ret.size() <= depth) {
            ret.resize(depth + 1);
            ret[depth] = root->val;
        } else {
            ret[depth] = max(ret[depth], root->val);
        }
        if (root->left != nullptr) dfs(ret, root->left, depth + 1);
        if (root->right != nullptr) dfs(ret, root->right, depth + 1);
    }
};

void test(const vector<ComplexVal>& vals, const vector<int>& expect) {
    Solution so;
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto ret = so.largestValues(root);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(vals);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 3, 2, 5, 3, null, 9}, {1, 3, 9});
    test({1, 2, 3}, {1, 3});
    return 0;
}
