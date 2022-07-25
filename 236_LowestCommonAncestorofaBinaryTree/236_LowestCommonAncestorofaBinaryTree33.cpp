#include "../inc.h"

// 大同小异
class Solution {
   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        unordered_map<TreeNode *, TreeNode *> fa;
        queue<TreeNode *> qu;
        qu.emplace(root);
        TreeNode *tmp = nullptr;
        int dp = 0;
        int dq = 0;
        int depth = 0;
        while (!qu.empty() && (dp == 0 || dq == 0)) {
            auto qsize = qu.size();
            ++depth;
            while (qsize-- != 0 && (dp == 0 || dq == 0)) {
                tmp = qu.front();
                qu.pop();
                if (tmp->left != nullptr) {
                    qu.emplace(tmp->left);
                    fa[tmp->left] = tmp;
                    if (tmp->left == p) dp = depth;
                    if (tmp->left == q) dq = depth;
                }
                if (tmp->right != nullptr) {
                    qu.emplace(tmp->right);
                    fa[tmp->right] = tmp;
                    if (tmp->right == p) dp = depth;
                    if (tmp->right == q) dq = depth;
                }
            }
        }
        while (dp < dq) {
            q = fa[q];
            --dq;
        }
        while (dq < dp) {
            p = fa[p];
            --dp;
        }
        while (p != q) {
            p = fa[p];
            q = fa[q];
        }
        return p;
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
