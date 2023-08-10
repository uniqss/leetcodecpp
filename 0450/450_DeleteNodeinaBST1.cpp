#include "../inc.h"

class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *curr = root, *left, *right, *parent = nullptr;
        bool isleft = true;
        while (curr != nullptr) {
            if (curr->val == key) {
                left = curr->left, right = curr->right;
                if (right != nullptr) {
                    if (parent == nullptr)
                        root = right;
                    else {
                        if (isleft)
                            parent->left = right;
                        else
                            parent->right = right;
                    }
                    if (left != nullptr) {
                        while (right->left != nullptr) {
                            right = right->left;
                        }
                        right->left = left;
                    }
                } else {
                    if (parent == nullptr)
                        root = left;
                    else {
                        if (isleft)
                            parent->left = left;
                        else
                            parent->right = left;
                    }
                }
                delete curr;
                break;
            } else if (curr->val > key) {
                parent = curr;
                curr = curr->left;
                isleft = true;
            } else {
                parent = curr;
                curr = curr->right;
                isleft = false;
            }
        }

        return root;
    }
};

void test(const vector<ComplexVal>& vals, int key, const vector<ComplexVal>& expect) {
    TreeNode* root = constructIntTree(vals);
    Solution so;
    auto ret = so.deleteNode(root, key);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retvals;
    treeToComplexValLevelOrder(ret, retvals);
    assert_eq_ret(expect, retvals);
    print(vals);
    print(key);
}

int main() {
    test({5, 3, 6, 2, 4, null, 7}, 5, {6, 3, 7, 2, 4});
    test({5, 3, 6, 2, 4, null, 7}, 3, {5, 4, 6, 2, null, null, 7});
    test({5, 3, 6, 2, 4, null, 7}, 0, {5, 3, 6, 2, 4, null, 7});
    test({}, 0, {});
    return 0;
}
