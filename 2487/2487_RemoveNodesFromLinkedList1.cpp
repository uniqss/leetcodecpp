#include "../inc.h"

class Solution {
   public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        ListNode fake(0, head);
        stk.push(&fake);
        while (head != nullptr) {
            while (stk.top()->val < head->val) stk.pop();
            stk.top()->next = head;
            stk.push(head);
            head = head->next;
        }
        return fake.next;
    }
};

void test(vector<int>&& vs, const vector<int>& expect) {
    save4print(vs);
    auto head = constructList(vs);
    auto ret = Solution().removeNodes(head);
    ListAutoReleaser _(ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expect, retvals);
}

int main() {
    test({5, 2, 13, 3, 8}, {13, 8});
    test({1, 1, 1, 1}, {1, 1, 1, 1});
    return 0;
}
