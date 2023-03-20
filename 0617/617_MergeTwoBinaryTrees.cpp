#include "../inc/inc.h"


class Solution {
   public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

void test(const vector<ComplexVal>& val1, const vector<ComplexVal>& val2, const vector<ComplexVal>& expect) {
    Solution so;
    auto root1 = constructIntTree(val1);
    auto root2 = constructIntTree(val2);
    TreeAutoReleaser _1(root1), _2(root2);

    auto ret = so.mergeTrees(root1, root2);
    auto etree = constructIntTree(expect);
    TreeAutoReleaser _e(etree);
    vector<int> rval;
    treeToIntVecLevelOrder(ret, rval);
    vector<int> eval;
    treeToIntVecLevelOrder(etree, eval);
    if (rval == eval) {
        print("ok");
    } else {
        print("not ok");
        print(val1);
        print(val2);
        print(expect);
        print(etree);
        print(ret);
        print();
    }
}

int main() {
    test({1, 3, 2, 5}, {2, 1, 3, null, 4, null, 7}, {3, 4, 5, 5, 4, null, 7});
    return 0;
}
