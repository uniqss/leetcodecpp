#include "../inc.h"

class Solution {
   public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {}
};

void test(const vector<ComplexVal>& vals, int target, int k, vector<int>&& expect) {
    Solution so;
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    TreeNode* tnode = treeFindUniqueNodeByVal(root, target);
    auto ret = so.distanceK(root, tnode, k);
    sort(expect.begin(), expect.end());
    sort(ret.begin(), ret.end());
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vals);
        print(target);
        print(k);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({0, 1, null, null, 2, null, 3, null, 4}, 3, 0, {3});
    test({0, 1, null, 3, 2}, 2, 1, {1});
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 2, {7, 4, 1});
    test({1}, 1, 3, {});
    return 0;
}
