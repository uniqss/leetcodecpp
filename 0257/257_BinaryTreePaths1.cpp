#include "../inc.h"

class Solution {
   public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        helper(root, ret, "", true);
        return ret;
    }
    void helper(TreeNode* root, vector<string>& ret, string curr, bool isroot) {
        if (root == nullptr) return;
        if (!isroot) curr += "->";
        curr += std::to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ret.emplace_back(curr);
        }
        helper(root->left, ret, curr, false);
        helper(root->right, ret, curr, false);
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