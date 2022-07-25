#include "../inc.h"

/*
我们甚至可以更激进一点直接栈不递归的dfs
*/
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        int depth = 0;
        stack<pair<TreeNode*, int>> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push({root, depth});
                ++depth;
                root = root->left;
            }
            root = stk.top().first;
            depth = stk.top().second;
            stk.pop();

            if ((int)ret.size() <= depth) ret.resize(depth + 1);
            ret[depth].emplace_back(root->val);

            root = root->right;
            ++depth;
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.levelOrder(root);
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
    test({3, 9, 20, null, null, 15, 7}, {{3}, {9, 20}, {15, 7}});
    test({1}, {{1}});
    test({}, {});
    return 0;
}
