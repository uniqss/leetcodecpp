#include "../inc.h"

class Solution {
   public:
    bool hasCycle(ListNode* head) {}
};

void test(ListNode* head) {
    Solution s;
    bool ret = s.hasCycle(head);
    cout << ret << endl;
}

int main() {
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
