#include "../inc.h"

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode fake(INT_MIN, head);
        ListNode *prev = &fake, *curr = nullptr;
        while (prev->next != nullptr) {
            if (prev->next->val == prev->val) {
                curr = prev->next;
                prev->next = curr->next;
                delete curr;
            } else {
                prev = prev->next;
            }
        }

        return fake.next;
    }
};

void test(const vector<int>& headvals, const vector<int>& expect) {
    ListNode* head = constructList(headvals);
    auto ret = Solution().deleteDuplicates(head);
    ListAutoReleaser _(ret);
    assert_eq_ret(expect, list2vals(ret));
}

int main() {
    test({1, 1, 2}, {1, 2});
    test({1, 1, 2, 3, 3}, {1, 2, 3});
    return 0;
}
