#include "../inc.h"

class Solution {
   public:
    ListNode* deleteMiddle(ListNode* head) {
        /*
        1       1
        1 2     2
        1 2 3   2
        */
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }
        ListNode fake(0, head);
        ListNode *slow = &fake, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;
        return fake.next;
    }
};

void test(const vector<int>& inarr, const vector<int>& expect) {
    auto head = constructList(inarr);
    Solution so;
    auto ret = so.deleteMiddle(head);
    ListAutoReleaser _(ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expect, retvals);
    print(inarr);
}

int main() {
    test({1, 3, 4, 7, 1, 2, 6}, {1, 3, 4, 1, 2, 6});
    test({1, 2, 3, 4}, {1, 2, 4});
    test({2, 1}, {2});
    test({2}, {});
    return 0;
}
