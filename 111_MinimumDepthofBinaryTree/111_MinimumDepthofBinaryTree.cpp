#include "../stl.h"

class Solution {
   public:
    int minDepth(TreeNode* root) {
    }
};

void test(const vector<ComplexVal>& vals, int expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);

    Solution so;
    auto ret = so.minDepth(root);
    if (ret != expect) {
        praw("not ok.");
        pvcomplex(vals);
        praw(expect);
        praw(ret);
    } else {
        praw("ok.");
    }
}

int main() {
    test({3, 9, 20, null, null, 15, 7}, 2);
    test({2, null, 3, null, 4, null, 5, null, 6}, 5);
    test({1, 2, 3, 4, 5}, 2);
    test({}, 0);
    return 0;
}

/*
[3,9,20,null,null,15,7]
[2,null,3,null,4,null,5,null,6]
*/
