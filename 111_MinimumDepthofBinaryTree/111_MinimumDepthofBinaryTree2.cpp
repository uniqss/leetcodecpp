#include "../stl.h"

// bfs
class Solution {
   public:
    int minDepth(TreeNode* root) {
        int ret = 0;
        if (root == nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto qsize = q.size();
            ++ret;
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                if (root->left == nullptr && root->right == nullptr) return ret;
                if (root->left != nullptr) q.push(root->left);
                if (root->right != nullptr) q.push(root->right);
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
        praw("not ok.");
        pvcomplex(vals);
        praw(expect);
        praw(ret);
    } else {
        praw("ok.");
    }
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, 2);
    test({2, null, 3, null, 4, null, 5, null, 6}, 5);
    return 0;
}

/*
[3,9,20,null,null,15,7]
[2,null,3,null,4,null,5,null,6]
*/
