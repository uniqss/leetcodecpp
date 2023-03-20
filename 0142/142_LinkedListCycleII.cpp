#include "../inc/inc.h"

class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {}
};

void test(ListNode* head, int expected) {
    Solution s;
    ListNode* node = s.detectCycle(head);
    int ret = node ? node->val : -1;
    if (ret == expected) {
        print("ok.");
    } else {
        print("no ok.");
        print(expected);
        print(ret);
        print();
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
