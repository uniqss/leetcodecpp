#include "../inc.h"

// 换汤不换药
class Solution {
   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        unordered_map<TreeNode *, TreeNode *> fa;
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> qu;
        qu.emplace(root);
        int count = 0;
        fa[root] = nullptr;
        while (!qu.empty() && count < 2) {
            auto qsize = qu.size();
            while (qsize-- != 0 && count < 2) {
                root = qu.front();
                qu.pop();
                if (root->left != nullptr) {
                    qu.emplace(root->left);
                    fa[root->left] = root;
                    if (root->left == p || root->left == q) ++count;
                }
                if (root->right != nullptr) {
                    qu.emplace(root->right);
                    fa[root->right] = root;
                    if (root->right == p || root->right == q) ++count;
                }
            }
        }
        while (p != nullptr) {
            visited[p] = true;
            p = fa[p];
        }
        while (q != nullptr) {
            if (visited[q]) return q;
            q = fa[q];
        }

        return nullptr;
    }
};

void test(vector<ComplexVal> &&vals, int vp, int vq, int vexpect) {
    TreeNode *root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    TreeNode *p = treeFindUniqueNodeByVal(root, vp);
    TreeNode *q = treeFindUniqueNodeByVal(root, vq);
    Solution so;
    TreeNode *ret = so.lowestCommonAncestor(root, p, q);
    int retval = ret->val;
    if (retval == vexpect) {
        print("ok.");
    } else {
        print("not ok.");
        print(vals);
        print(vp);
        print(vq);
        print(vexpect);
        print(retval);
        print();
    }
}

int main() {
    test({-1, 0, 3, -2, 4, null, null, 8}, 8, 4, 0);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 0, 8, 1);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 1, 3);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 4, 5);
    test({1, 2}, 1, 2, 1);
    return 0;
}

/*
[-1,0,3,-2,4,null,null,8]
8
4

[3,5,1,6,2,0,8,null,null,7,4]
5
1
[3,5,1,6,2,0,8,null,null,7,4]
5
4
[1,2]
1
2
[3,5,1,6,2,0,8,null,null,7,4]
0
8

*/
