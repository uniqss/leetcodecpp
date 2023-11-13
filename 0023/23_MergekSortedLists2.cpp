#include "../inc.h"

/*
wholly high!
*/
struct Status {
    int val;
    ListNode* node;
    Status(int v, ListNode* p) : val(v), node(p) {}
    bool operator<(const Status& rhs) const { return val > rhs.val; }
};
class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Status> pq;
        for (auto l : lists) {
            if (l != nullptr) pq.push({l->val, l});
        }
        ListNode fake, *prev = &fake;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            ListNode* node = new ListNode(curr.val);
            prev->next = node;
            prev = node;
            if (curr.node->next != nullptr) pq.emplace(curr.node->next->val, curr.node->next);
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
