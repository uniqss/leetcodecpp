#include "../inc.h"

class Solution {
   public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ret;
        if (tree == nullptr) return ret;
        queue<TreeNode*> q;
        q.push(tree);
        while (!q.empty()) {
            auto qsize = q.size();
            ListNode fake;
            ListNode* tail = &fake;
            for (size_t i = 0; i < qsize; ++i) {
                auto curr = q.front();
                ListNode* node = new ListNode(curr->val, nullptr);
                tail->next = node;
                tail = node;
                q.pop();
                if (curr->left != nullptr) q.emplace(curr->left);
                if (curr->right != nullptr) q.emplace(curr->right);
            }
            ret.emplace_back(fake.next);
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    save4print(vals);
    auto tree = constructIntTree(vals);
    TreeAutoReleaser _(tree);
    auto ret = Solution().listOfDepth(tree);
    vector<vector<int>> retvals;
    for (size_t i = 0; i < ret.size(); ++i) {
        auto retval = list2vals(ret[i]);
        retvals.push_back(retval);
    }
    assert_eq_ret(expect, retvals);
}

int main() {
    test({1, 2, 3, 4, 5, null, 7, 8}, {{1}, {2, 3}, {4, 5, 7}, {8}});
    return 0;
}
