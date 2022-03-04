#include "inc.h"

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

void test(ListNode* head) {
    Solution s;
    ListNode* node = s.detectCycle(head);
    if (node != nullptr) {
        cout << node->val << endl;
    } else {
        cout << -1 << endl;
    }
}

int main(int argc, char const* argv[]) {
    ListNode* head = nullptr;

    head = constructList({});
    test(head);
    releaseLinkedList(head);

    head = constructList({1});
    test(head);
    releaseLinkedList(head);

    head = constructList({1});
    head->next = head;
    test(head);
    head->next = nullptr;
    releaseLinkedList(head);

    head = constructList({1, 2});
    head->next->next = head;
    test(head);
    head->next->next = nullptr;
    releaseLinkedList(head);

    head = constructList({1, 2});
    test(head);

    head = constructList({1, 2, 3});
    head->next->next->next = head->next;
    test(head);
    head->next->next->next = nullptr;
    releaseLinkedList(head);

    head = constructList({1, 2, 3});
    test(head);

    return 0;
}
