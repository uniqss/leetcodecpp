#include "../inc.h"

class Solution {
   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {}
};

void test(vector<int>&& inorder, vector<int>&& postorder, const vector<ComplexVal>& expect) {
    Solution so;
    auto ret = so.buildTree(inorder, postorder);
    TreeAutoReleaser _1(ret);
    auto etree = constructIntTree(expect);
    TreeAutoReleaser _2(etree);
    vector<int> ret_vec;
    treeToIntVecLevelOrder(ret, ret_vec);
    vector<int> expect_vec;
    treeToIntVecLevelOrder(etree, expect_vec);
    if (ret_vec == expect_vec) {
        print("ok");
    } else {
        print("not ok");
        print(inorder);
        print(postorder);
        print(expect);
        print(etree);
        print(ret);
        print();
    }
}

int main() {
    test({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3}, {3, 9, 20, null, null, 15, 7});
    test({-1}, {-1}, {-1});
    return 0;
}