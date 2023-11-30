#include "../inc.h"

// 还是回归1的思路用bfs，但是只用遍历一遍，性能还是会有所提高的，尤其是公共节点比较多的时候
// bfs比dfs要方便一点
// 因为【我们横向剪掉树的某些层以下的叶节点(双节点都遇到了的层以下甚至包括最后一个节点的同层所有右边子节点)】比【我们根据一定的条件判定来纵向剪掉某些枝】要简单
// 无论什么剪枝策略，要保证两点：第一，两个节点都已触摸。第二，从根到两节点的所有中间节点都已触摸。
class Solution {
    unordered_map<TreeNode*, TreeNode*> fa;
    unordered_map<TreeNode*, bool> visited;

   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root] = nullptr;
        bfs(root, p, q);
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
    void bfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        qu.emplace(root);
        int count = 0;
        while (!qu.empty()) {
            root = qu.front();
            qu.pop();
            if (root->left != nullptr) {
                qu.emplace(root->left);
                if (root->left == p || root->left == q) ++count;
                fa[root->left] = root;
            }
            if (root->right != nullptr) {
                qu.emplace(root->right);
                if (root->right == p || root->right == q) ++count;
                fa[root->right] = root;
            }
            if (count >= 2) break;
        }
    }
};

void test(vector<ComplexVal>&& vals, int vp, int vq, int vexpect) {
    save4print(vals, vp, vq);
    TreeNode *root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    TreeNode *p = treeFindUniqueNodeByVal(root, vp), *q = treeFindUniqueNodeByVal(root, vq);
    TreeNode *ret = Solution().lowestCommonAncestor(root, p, q);
    int retval = ret->val;
    assert_eq_ret(vexpect, retval);
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
