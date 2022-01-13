#include "../stl.h"

class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
    }
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    pvcomplex(vals);
    Node* root = constructNArrayTree(vals);
    pNArrayTree(root);
    Solution so;
    auto ret = so.levelOrder(root);
    if (ret != expect) {
        praw("not ok");
        pvcomplex(vals);
        pvvraw(expect);
        pvvraw(ret);
    } else {
        praw("ok.");
    }
}

int main() {
    test({1, null, 3, 2, 4, null, 5, 6}, {{1}, {3, 2, 4}, {5, 6}});
    test({1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14}, {{1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}});
    return 0;
}
