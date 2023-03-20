#include "../inc/inc.h"

class Solution {
   public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == nullptr) return ret;
        queue<TreeNode*> nodes;
        queue<string> paths;
        nodes.push(root);
        paths.push(to_string(root->val));
        while (!nodes.empty()) {
            auto qsize = nodes.size();
            for (size_t i = 0; i < qsize; ++i) {
                root = nodes.front();
                nodes.pop();
                string s = paths.front();
                paths.pop();
                if (root->left == nullptr && root->right == nullptr) {
                    ret.emplace_back(s);
                }
                if (root->left) {
                    nodes.emplace(root->left);
                    paths.emplace(s + "->" + to_string(root->left->val));
                }
                if (root->right) {
                    nodes.emplace(root->right);
                    paths.emplace(s + "->" + to_string(root->right->val));
                }
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