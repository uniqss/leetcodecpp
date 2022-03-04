#include "../inc.h"

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode tmp;
        ListNode* prev = &tmp;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        if (list1 != nullptr) prev->next = list1;
        if (list2 != nullptr) prev->next = list2;
        return tmp.next;
    }
};

void test(const std::vector<int>& v1, const std::vector<int>& v2) {
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;
    Solution s;
    ListNode* ret = nullptr;

    head1 = constructList(v1);
    pLinkedList(head1);
    head2 = constructList(v2);
    pLinkedList(head2);
    ret = s.mergeTwoLists(head1, head2);
    pLinkedList(ret);
    releaseLinkedList(ret);
}

int main() {
    vector<int> vi1;
    vector<int> vi2;

    vi1 = {1, 2, 4};
    vi2 = {1, 3, 4};
    test(vi1, vi2);

    vi1 = {};
    vi2 = {};
    test(vi1, vi2);

    vi1 = {};
    vi2 = {0};
    test(vi1, vi2);

    return 0;
}
