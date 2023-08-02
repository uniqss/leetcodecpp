#include "../inc.h"

class Solution {
   public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *odd = head, *even = head->next, *evenhead = even, *curr = even->next, *next;
        bool isodd = true;
        while (curr != nullptr) {
            next = curr->next;
            if (isodd) {
                odd->next = curr;
                odd = odd->next;
            } else {
                even->next = curr;
                even = even->next;
            }
            curr = next;
            isodd = !isodd;
        }
        even->next = nullptr;
        odd->next = evenhead;

        return head;
    }
};

void test(const vector<int>& arrin, const vector<int>& expect) {
    Solution so;
    ListNode* head = constructList(arrin);
    ListAutoReleaser _(head);
    auto ret = so.oddEvenList(head);
    auto retval = list2vals(ret);
    assert_eq_ret(expect, retval);
    print(arrin);
}

int main() {
    test({1, 2, 3, 4, 5}, {1, 3, 5, 2, 4});
    test({2, 1, 3, 5, 6, 4, 7}, {2, 3, 6, 7, 1, 5, 4});
    return 0;
}
