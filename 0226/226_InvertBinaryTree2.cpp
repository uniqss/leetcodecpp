#include "../inc/inc.h"

// 这题其实so easy，随便抓个树的遍历，只要保证每个节点只访问一次即可
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr = nullptr;
        while (!q.empty()) {
            size_t qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                curr = q.front();
                q.pop();
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
                std::swap(curr->left, curr->right);
            }
        }
        return root;
    }
};

void test(const vector<int>& vals, const vector<int>& expect) {
    TreeNode* root = constructIntBinaryTreeLayerOrder(vals);
    TreeAutoReleaser _(root);

    Solution so;
    TreeNode* ret = so.invertTree(root);
    vector<int> ret_vec;
    treeToIntVecLevelOrder(ret, ret_vec);
    if (ret_vec != expect) {
        print("not ok.");
        print(vals);
        print(expect);
        print(ret_vec);
    } else {
        print("ok.");
    }
}

int main() {
    test({4, 2, 7, 1, 3, 6, 9}, {4, 7, 2, 9, 6, 3, 1});
    test({2, 1, 3}, {2, 3, 1});
    test({}, {});
    return 0;
}

/*
[4,2,7,1,3,6,9]
[2,1,3]
[]
*/
