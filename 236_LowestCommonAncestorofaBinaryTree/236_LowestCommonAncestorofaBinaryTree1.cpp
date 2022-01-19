#include "../stl.h"

// 最初思路是找出从根到自己的路径，再依次从头到尾找到两个路径中最后一个相同节点，即是解。这里已经优化了。树没有排序没有规整的情况下，最坏一定是o(n)，随便啥解法
class Solution {
    unordered_map<TreeNode*, TreeNode*> mapCurrParent_;

   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int dp = 0;
        findPath(root, p, dp);
        int dq = 0;
        findPath(root, q, dq);
        while (dp < dq) {
            q = mapCurrParent_.find(q)->second;
            --dq;
        }
        while (dq < dp) {
            p = mapCurrParent_.find(p)->second;
            --dp;
        }
        while (p != q) {
            p = mapCurrParent_.find(p)->second;
            q = mapCurrParent_.find(q)->second;
        }

        return p;
    }
    void findPath(TreeNode* root, TreeNode* node, int& depth) {
        queue<TreeNode*> q;
        depth = 1;
        if (root == nullptr || node == root) return;
        q.emplace(root);
        while (!q.empty()) {
            auto qsize = q.size();
            ++depth;
            while (qsize-- != 0) {
                root = q.front();
                q.pop();
                if (root->left != nullptr) {
                    q.emplace(root->left);
                    mapCurrParent_[root->left] = root;
                }
                if (root->right != nullptr) {
                    q.emplace(root->right);
                    mapCurrParent_[root->right] = root;
                }
                if (root->left == node || root->right == node) return;
            }
        }
    }
};

void test(vector<ComplexVal>&& vals, int vp, int vq, int vexpect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    TreeNode* p = treeFindUniqueNodeByVal(root, vp);
    TreeNode* q = treeFindUniqueNodeByVal(root, vq);
    Solution so;
    TreeNode* ret = so.lowestCommonAncestor(root, p, q);
    int retval = ret->val;
    if (retval == vexpect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        praw(vp);
        praw(vq);
        praw(vexpect);
        praw(retval);
        pnewline();
    }
}

int main() {
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 0, 8, 1);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 1, 3);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 4, 5);
    test({1, 2}, 1, 2, 1);
    return 0;
}

/*
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
