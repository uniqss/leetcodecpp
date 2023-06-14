#include "../inc.h"

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 不讲武德
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

void test(const vector<ComplexVal>& vp, const vector<ComplexVal>& vq, bool expect) {
    TreeNode* p = constructIntTree(vp);
    TreeNode* q = constructIntTree(vq);
    TreeAutoReleaser _(p, q);
    Solution so;
    auto ret = so.isSameTree(p, q);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vp);
        print(vq);
        print(expect);
        print(ret);
    }
}

int main() {
    test({}, {}, true);
    test({1, 2, 3}, {1, 2, 3}, true);
    test({1, 2}, {1, null, 2}, false);
    return 0;
}
