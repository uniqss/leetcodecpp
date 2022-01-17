#include "../stl.h"

class Codec {
   public:
    string serialize(TreeNode* root) {
    }

    TreeNode* deserialize(string data) {
    }
};

void test(const vector<ComplexVal>& vals, const string& expect) {
    string str;
    vcomplexToString(str, vals);
    Codec co;
    TreeNode* root = co.deserialize(str);
    TreeAutoReleaser _(root);
    string ret = co.serialize(root);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        praw(expect);
        praw(ret);
        pTree(root);
    }
}

int main() {
    test({1, 2, 3, null, null, 4, 5}, "[1,2,3,null,null,4,5]");
    test({1, 2, 3, null, null, 4, 5, 6, 7}, "[1,2,3,null,null,4,5,6,7]");
    test({4, -7, -3, null, null, -9, -3, 9, -7, -4, null, 6, null, -6, -6, null, null, 0, 6, 5, null, 9, null, null, -1, -4, null, null, null, -2}, "[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]");
    test({}, "[]");
    return 0;
}

/*
[1,2,3,null,null,4,5]
[]
[1,2,3,null,null,4,5,6,7]
[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]

*/
