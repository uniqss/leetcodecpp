#include "../inc/inc.h"

// bfs
class Solution {
   public:
    int minDepth(TreeNode* root) {
        int ret = 0;
        if (root == nullptr) return ret;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            auto qsize = q.size();
            ++ret;
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                if (root->left == nullptr && root->right == nullptr) return ret;
                if (root->left != nullptr) q.emplace(root->left);
                if (root->right != nullptr) q.emplace(root->right);
            }
        }
        return -1;
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);

    Solution so;
    auto ret = so.minDepth(root);
    if (ret != expect) {
        print("not ok.");
        print(vals);
        print(expect);
        print(ret);
    } else {
        print("ok.");
    }
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, 2);
    test({2, null, 3, null, 4, null, 5, null, 6}, 5);
    test({}, 0);
    return 0;
}

/*
[3,9,20,null,null,15,7]
[2,null,3,null,4,null,5,null,6]
*/
