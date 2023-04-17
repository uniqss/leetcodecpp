#include "../inc.h"


class Solution {
   public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        /*
              4
          2      6
        1   3 5    7

        4 2 6 1 3 5 7
        4 6 2 1 3 5 7
        4 2 1 3 6 5 7
        4 2 3 1 6 5 7
        4 2 3 6 1 5 7
        只要父在子前，左右不论的任意组合，包括右在左前、右在左后左左子前、右在左后左左子后左右子前、右在左后在左左子后在左右子后，所有只要父在子前，应该是个backtrack回溯

        */
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        if (root->left == nullptr && root->right == nullptr) return {{root->val}};
        auto l = BSTSequences(root->left);
        auto r = BSTSequences(root->right);
        if (root->left == nullptr) {
            for (auto& it : r) {
                if (it.empty()) continue;
                it.resize(it.size() + 1);
                std::move(it.begin(), it.end(), it.begin() + 1);
                it[0] = root->val;
            }
            return r;
        }
        if (root->right == nullptr) {
            for (auto& it : l) {
                if (it.empty()) continue;
                it.resize(it.size() + 1);
                std::move(it.begin(), it.end(), it.begin() + 1);
                it[0] = root->val;
            }
            return l;
        }

        for (auto itl : l) {
            if (itl.empty()) continue;
            for (auto itr : r) {
                if (itr.empty()) continue;
                auto sizel = itl.size();
                auto sizer = itr.size();
                /*
                1 1
                0 0 0
                0 0 0 1 1
                0 0 1 0 1
                0 0 1 1 0
                0 1 0 0 1
                0 1 0 1 0
                0 1 1 0 0
                1 0 0 0 1
                1 0 0 1 0
                1 0 1 0 0
                1 1 0 0 0
                C(5, 2)  5 * 4 / 2 = 10
                */
                vector<int> curr(sizel + sizer, 0);
                std::fill_n(curr.begin() + sizer, sizel, 1);
                while (true) {
                    // fill curr to ret
                    vector<int> val(sizel + sizer + 1);
                    val[0] = root->val;
                    size_t idxl = 0, idxr = 0;
                    for (size_t i = 1; i <= sizel + sizer; ++i) {
                        if (curr[i]) {
                            root[i] = itl[idxl++];
                        } else {
                            root[i] = itr[idxr++];
                        }
                    }

                    // move larger, keep bits count
                    
                    // if not valid, break
                }
            }
        }


        return ret;
    }
};

void test(const vector<ComplexVal>& vals, vector<vector<int>>&& expect) {
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);

    Solution so;
    auto ret = so.BSTSequences(root);
    auto ret_bk = ret;
    std::sort(ret.begin(), ret.end());
    std::sort(expect.begin(), expect.end());
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vals);
        print(expect);
        print(ret_bk);
        print(ret);
        print();
    }
}

int main() {
    test({2, 1, 3}, {{2, 1, 3}, {2, 3, 1}});
    return 0;
}
