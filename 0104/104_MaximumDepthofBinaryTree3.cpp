#include "../inc.h"

// 广度优先 Breadth-First-Search bfs
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int ret = 0;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                if (root->left != nullptr) q.emplace(root->left);
                if (root->right != nullptr) q.emplace(root->right);
            }
            ++ret;
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, int expected) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);

    Solution so;
    auto ret = so.maxDepth(root);
    if (expected == ret) {
        print("ok.");
    } else {
        print("not ok.");
        print(vals);
        print(expected);
        print(ret);
    }
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, 3);
    test({1, null, 2}, 2);
    test({}, 0);

    return 0;
}

/*
[3,9,20,null,null,15,7]
[1,null,2]
3
2
*/
