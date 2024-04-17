#include "../inc.h"

/*
time complexity: O(n)
space complexity: O(n)

*/
class Solution {
    unordered_map<TreeNode*, TreeNode*> parents;
    vector<string> values;

   public:
    string smallestFromLeaf(TreeNode* root) {
        parents[root] = nullptr;
        dfs(root);
        // sort(values.begin(), values.end());
        int idx = 0, n = values.size();
        for (int i = 1; i < n; ++i) {
            if (values[idx] > values[i]) idx = i;
        }
        return values[idx];
    }
    void dfs(TreeNode* curr) {
        if (curr == nullptr) return;
        if (curr->left == nullptr && curr->right == nullptr) {
            string val;
            while (curr != nullptr) {
                val.push_back('a' + curr->val);
                curr = parents[curr];
            }
            values.emplace_back(val);
            return;
        }
        if (curr->left) parents[curr->left] = curr, dfs(curr->left);
        if (curr->right) parents[curr->right] = curr, dfs(curr->right);
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
