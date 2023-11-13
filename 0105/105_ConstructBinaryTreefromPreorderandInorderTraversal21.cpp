#include "../inc.h"

/*
没刚过，对照了一下２里面的写法修正的，这样写的理解成本很高，不如２的写法
*/
class Solution {
    unordered_map<int, int> dict_inorder;

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            dict_inorder[inorder[i]] = i;
        }
        return helper(preorder, 0, 0, preorder.size() - 1);
    }
    TreeNode* helper(const vector<int>& preorder, int pidx, int il, int ir) {
        if (il > ir) return nullptr;
        TreeNode* curr = new TreeNode(preorder[pidx], nullptr, nullptr);
        if (il == ir) return curr;
        int vcurr = preorder[pidx], iidx = dict_inorder[vcurr];
        curr->left = helper(preorder, pidx + 1, il, iidx - 1);
        curr->right = helper(preorder, pidx + iidx + 1 - il, iidx + 1, ir);
        return curr;
    }
};

void test(vector<int>&& preorder, vector<int>&& inorder, vector<ComplexVal>&& expect) {
    save4print(preorder, inorder);
    TreeNode* ret = Solution().buildTree(preorder, inorder);
    TreeNode* expect_tree = constructIntTree(expect);
    TreeAutoReleaser _2(ret, expect_tree);
    vector<int> vret, vexpect;
    treeToIntVecLevelOrder(ret, vret);
    treeToIntVecLevelOrder(expect_tree, vexpect);
    assert_eq_ret(vexpect, vret);
}

int main() {
    test({4, 2, 1, 3, 6, 5, 7}, {1, 2, 3, 4, 5, 6, 7}, {4, 2, 6, 1, 3, 5, 7});
    test({1, 2, 3}, {2, 3, 1}, {1, 2, null, null, 3});
    test({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7}, {3, 9, 20, null, null, 15, 7});
    test({-1}, {-1}, {-1});
    return 0;
}

/*
[1,2,3]
[2,3,1]
[1,2,null,null,3]


[3,9,20,15,7]
[9,3,15,20,7]
[-1]
[-1]

[3,9,20,null,null,15,7]
[-1]
*/
