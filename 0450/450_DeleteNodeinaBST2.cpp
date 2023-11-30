#include "../inc.h"

// 略为取巧，学习了链表中的假头节点，规避了parent的复杂处理逻辑
class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode fake(0, nullptr, root), *parent = &fake, *curr = root;
        bool isleft = false;
        while (curr != nullptr) {
            if (curr->val == key) {
                TreeNode *l = curr->left, *r = curr->right;
                if (l == nullptr) {
                    if (isleft)
                        parent->left = r;
                    else
                        parent->right = r;
                } else if (r == nullptr) {
                    if (isleft)
                        parent->left = l;
                    else
                        parent->right = l;
                } else {
                    TreeNode* lmost = r;
                    while (lmost->left != nullptr) lmost = lmost->left;
                    if (isleft) {
                        parent->left = r;
                    } else {
                        parent->right = r;
                    }
                    lmost->left = l;
                }
                return fake.right;
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

        return fake.right;
    }
};

void test(const vector<ComplexVal>& vals, int key, const vector<ComplexVal>& expect) {
    save4print(vals, key);
    TreeNode* root = constructIntTree(vals);
    auto ret = Solution().deleteNode(root, key);
    TreeAutoReleaser _(ret);
    vector<ComplexVal> retvals;
    treeToComplexValLevelOrder(ret, retvals);
    assert_eq_ret(expect, retvals);
}

int main() {
    test({5, 3, 6, 2, 4, null, 7}, 5, {6, 3, 7, 2, 4});
    test({5, 3, 6, 2, 4, null, 7}, 3, {5, 4, 6, 2, null, null, 7});
    test({5, 3, 6, 2, 4, null, 7}, 0, {5, 3, 6, 2, 4, null, 7});
    test({}, 0, {});
    return 0;
}
