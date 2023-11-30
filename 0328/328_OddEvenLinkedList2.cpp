#include "../inc.h"

class Solution {
   public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode fake1, fake2, *prev1 = &fake1, *prev2 = &fake2;
        bool odd = true;
        while (head != nullptr) {
            if (odd)
                prev1->next = head, prev1 = prev1->next;
            else
                prev2->next = head, prev2 = prev2->next;
            head = head->next, odd = !odd;
        }
        prev2->next = nullptr, prev1->next = fake2.next;
        return fake1.next;
    }
};

void test(const vector<int>& arrin, const vector<int>& expect) {
    save4print(arrin);
    ListNode* head = constructList(arrin);
    ListAutoReleaser _(head);
    auto ret = Solution().oddEvenList(head);
    auto retval = list2vals(ret);
    assert_eq_ret(expect, retval);
}

int main() {
    test({1, 2, 3, 4, 5}, {1, 3, 5, 2, 4});
    test({2, 1, 3, 5, 6, 4, 7}, {2, 3, 6, 7, 1, 5, 4});
    return 0;
}
