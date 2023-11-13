#include "../inc.h"

class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

void test(ListNode* head, int expected) {
    ListNode* node = Solution().detectCycle(head);
    int ret = node ? node->val : -1;
    assert_eq_ret(expected, ret);
}

int main(int argc, char const* argv[]) {
    ListNode* head = nullptr;

    head = constructList({});
    test(head, -1);
    releaseLinkedList(head);

    head = constructList({1});
    test(head, -1);
    releaseLinkedList(head);

    head = constructList({1});
    head->next = head;
    test(head, 1);
    head->next = nullptr;
    releaseLinkedList(head);

    head = constructList({1, 2});
    head->next->next = head;
    test(head, 1);
    head->next->next = nullptr;
    releaseLinkedList(head);

    head = constructList({1, 2});
    test(head, -1);
    releaseLinkedList(head);

    head = constructList({1, 2, 3});
    head->next->next->next = head->next;
    test(head, 2);
    head->next->next->next = nullptr;
    releaseLinkedList(head);

    head = constructList({1, 2, 3});
    test(head, -1);
    releaseLinkedList(head);

    return 0;
}
