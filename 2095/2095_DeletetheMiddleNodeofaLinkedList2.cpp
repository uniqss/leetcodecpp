#include "../inc.h"

class Solution {
   public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode fake(0, head), *slow = &fake, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        if (slow->next != nullptr) slow->next = slow->next->next;
        delete fast;
        return fake.next;
    }
};

void test(const vector<int>& inarr, const vector<int>& expect) {
    save4print(inarr);
    auto head = constructList(inarr);
    auto ret = Solution().deleteMiddle(head);
    ListAutoReleaser _(ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expect, retvals);
}

int main() {
    test({1, 3, 4, 7, 1, 2, 6}, {1, 3, 4, 1, 2, 6});
    test({1, 2, 3, 4}, {1, 2, 4});
    test({2, 1}, {2});
    test({2}, {});
    return 0;
}
