#include "../inc.h"

// 本质上是2的变种，值得学习的是这里不需要封结构体包一层，语义很清晰，而且支持多个想用哪个用哪个
class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct ListNodeCmp {
            bool operator()(ListNode* lhs, ListNode* rhs) const { return lhs->val > rhs->val; }
        };
        priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> q;
        for (auto l : lists)
            if (l) q.emplace(l);
        ListNode fake, *pre = &fake;
        while (!q.empty()) {
            ListNode* curr = q.top();
            q.pop();
            pre->next = curr;
            pre = pre->next;
            curr = curr->next;
            if (curr) q.emplace(curr);
        }
        return fake.next;
    }
};

void test(vector<vector<int>>&& listvals, const vector<int>& expect) {
    save4print(listvals);
    vector<ListNode*> lists;
    ListAutoReleaser _;
    for (int i = 0; i < listvals.size(); ++i) {
        lists.emplace_back(constructList(listvals[i]));
    }
    _.Append(lists);
    auto ret = Solution().mergeKLists(lists);
    _.Append(ret);
    assert_eq_ret(expect, list2vals(ret));
}

int main() {
    test({{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6});
    test({}, {});
    test({{}}, {});
    return 0;
}
