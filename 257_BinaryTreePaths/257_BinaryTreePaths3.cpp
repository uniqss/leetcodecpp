#include "../inc.h"

class Solution {
   public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == nullptr) return ret;
        helper(root, {root->val}, ret);
        return ret;
    }
    void helper(TreeNode* root, vector<int> val, vector<string>& ret) {
        if (root->left == nullptr && root->right == nullptr) {
            string path;
            for (size_t i = 0; i < val.size(); ++i) {
                if (i > 0) path += "->";
                path += to_string(val[i]);
            }
            ret.emplace_back(path);

            return;
        }
        if (root->left) {
            val.push_back(root->left->val);
            helper(root->left, val, ret);
            val.pop_back();
        }
        if (root->right) {
            val.push_back(root->right->val);
            helper(root->right, val, ret);
            val.pop_back();
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
        print("ok");
    } else {
        print("not ok.");
        print(vals);
        print(expect);
        print(ret);
    }
}

int main() {
    test({1, 2, 3, null, 5}, {"1->2->5", "1->3"});
    test({1}, {"1"});
    return 0;
}