#include "../inc.h"

/*
time complexity: O(n)
space complexity: O(1)

*/
class Solution {
    string ret;

   public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ret;
    }
    void dfs(TreeNode* curr, string val) {
        if (curr == nullptr) return;
        val.push_back('a' + curr->val);
        if (curr->left == nullptr && curr->right == nullptr) {
            reverse(val.begin(), val.end());
            if (ret.empty())
                ret = val;
            else
                ret = min(ret, val);
        }
        dfs(curr->left, val);
        dfs(curr->right, val);
    }
};

void test(vector<ComplexVal>&& vals, const string& expect) {
    save4print(vals, expect);
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    assert_eq_ret(expect, Solution().smallestFromLeaf(root));
}

int main() {
    test({0, 1, 2, 3, 4, 3, 4}, "dba");
    test({25, 1, 3, 1, 3, 0, 2}, "adz");
    test({2, 2, 1, null, 1, 0, null, 0}, "abc");
    return 0;
}
