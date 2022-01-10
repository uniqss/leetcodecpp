#include "../stl.h"

// recursive
class Solution {
   public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        helper(ret, root);
        return ret;
    }
    void helper(vector<int>& ret, Node* root) {
        if (root == nullptr) return;
        for (auto child : root->children) {
            helper(ret, child);
        }
        ret.push_back(root->val);
    }
};

void test(const vector<ComplexVal>& vals, const vector<int>& expect) {
    pvcomplex(vals);
    Node* root = constructNArrayTree(vals);
    pNArrayTree(root);
    Solution so;
    vector<int> ret = so.postorder(root);
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
    test({1, null, 3, 2, 4, null, 5, 6}, {5, 6, 3, 2, 4, 1});
    test({1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14}, {2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1});
    return 0;
}