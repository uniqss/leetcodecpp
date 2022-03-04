#include "../inc.h"

// recursive
class Solution {
   public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        helper(ret, root);
        return ret;
    }
    void helper(vector<int>& ret, Node* root) {
        if (root == nullptr) return;
        ret.emplace_back(root->val);
        std::for_each(root->children.begin(), root->children.end(), [&](Node* node) { helper(ret, node); });
    }
};

void test(const vector<ComplexVal>& vals, const vector<int>& expect) {
    pvcomplex(vals);
    Node* root = constructNArrayTree(vals);
    pNArrayTree(root);
    Solution so;
    vector<int> ret = so.preorder(root);
    if (ret != expect) {
        praw("not ok");
        pvcomplex(vals);
        pvraw(expect);
        pvraw(ret);
    } else {
        praw("ok.");
    }
}

int main() {
    test({1, null, 3, 2, 4, null, 5, 6}, {1, 3, 5, 6, 2, 4});
    test({1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14}, {1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10});
    return 0;
}
