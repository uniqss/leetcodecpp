#include "../inc.h"

/*
              4
          2      6
        1   3 5    7
当前路径|可选择列表
|4
    选择4
    4|2,6
        选择2
        4,2|6,1,3
            选择6
            4,2,6|1,3,5,7
                选择1
                4,2,6,1|3,5,7
                    选择3
                    4,2,6,1,3|5,7
                        选择5
                        4,2,6,1,3,5|7
                            选择7
                            4,2,6,1,3,5,7|空
                                选择，可先为空，把路径加入返回值
                选择3
                4,2,6,3|1,5,7
                选择5
                4,2,6,5|1,3,7
                选择7
                4,2,6,7|1,3,5
        选择6
        4,6|2,5,7

第一个必须是4，下一个只能有2种选择，2，6
    第二个如选择2，下一个有3种选择，1，3，6
        第三个如选择1，下一个有2种选择，3，6
            第四个如选择3，下一个有1种选择 6
            第四个如选择6，下一个有3种选择 3，5，7
        第三个如选择3，下一个有2种选择，1，6
        第三个如选择6，下一个有4种选择，1，3，5，7
    第二个如选择6，下一个有3种选择，2，5，7

对于每一步的选择：
    输入：
        可选择列表
        当前路径
    操作：
        从列表中选择一个，加入当前路径
        从可选择列表中移除当前选择的
        把当前选择的非空子节点，加入下一步的可选择列表
*/

class Solution {
    vector<int> path;
    vector<vector<int>> ret;

   public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if (root == nullptr) return {{}};
        deque<TreeNode*> dq;
        dq.push_back(root);
        dfs(dq);
        return ret;
    }
    void dfs(deque<TreeNode*>& dq) {
        if (dq.empty()) {
            ret.push_back(path);
            return;
        }
        size_t size = dq.size();
        for (size_t i = 0; i < size; ++i) {
            TreeNode* curr = dq.front();
            dq.pop_front();

            path.push_back(curr->val);
            if (curr->left) dq.push_back(curr->left);
            if (curr->right) dq.push_back(curr->right);

            dfs(dq);

            if (curr->left) dq.pop_back();
            if (curr->right) dq.pop_back();

            dq.push_back(curr);

            path.pop_back();
        }
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
