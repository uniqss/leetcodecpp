#include "../inc.h"

/*
这里关键是totally的理解，它的意思是，本次调用是否check整个树要完全相等，包括所有节点值和结构
false的时候表示需要递归去访问所有子节点再判定是否整个棵树相等
这个题目好像用中序不太好搞
   4
       3
     2

   4
      2
         3
  这两个的中序都是 423但是树异构
如果允许带上nullptr，可以搞，否则不行
4 null 2 3
4 null 2 null 3
*/
class Solution {
   public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) { return helper(t1, t2, false); }
    bool helper(TreeNode* t1, TreeNode* t2, bool totally) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        if (totally) {
            if (t1->val != t2->val) return false;
            return helper(t1->left, t2->left, true) && helper(t1->right, t2->right, true);
        } else {
            if (helper(t1, t2, true)) return true;
            if (helper(t1->left, t2, false)) return true;
            if (helper(t1->right, t2, false)) return true;
        }
        return false;
    }
};

void test(const vector<ComplexVal>& v1, const vector<ComplexVal>& v2, bool expect) {
    save4print(v1, v2);
    auto t1 = constructIntTree(v1);
    auto t2 = constructIntTree(v2);
    TreeAutoReleaser _(t1, t2);
    assert_eq_ret(expect, Solution().checkSubTree(t1, t2));
}

int main() {
    test({2, 4, null, 3}, {2, 3}, false);
    test({1, 2, null, 4, null, 3}, {2, 3}, false);
    test({1, 2, 3}, {2}, true);
    return 0;
}
