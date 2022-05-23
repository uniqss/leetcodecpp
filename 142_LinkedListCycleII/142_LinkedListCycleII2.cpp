#include "../inc.h"

class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (fast == nullptr) return nullptr;
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};

void test(ListNode* head, int expected) {
    Solution s;
    ListNode* node = s.detectCycle(head);
    int ret = node ? node->val : -1;
    if (ret == expected) {
        praw("ok.");
    } else {
        praw("no ok.");
        praw(expected);
        praw(ret);
        pnewline();
    }
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
