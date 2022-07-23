#include "../inc.h"

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {}
};

void test(const std::vector<int>& v1, const std::vector<int>& v2, const std::vector<int>& expect) {
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;
    Solution s;
    ListNode* ret = nullptr;

    head1 = constructList(v1);
    head2 = constructList(v2);
    ret = s.mergeTwoLists(head1, head2);
    auto retval = list2vals(ret);
    if (retval == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pLinkedList(head1);
        pLinkedList(head2);
        pLinkedList(ret);
        pnewline();
    }
    releaseLinkedList(ret);
}

int main() {
    test({1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4});
    test({}, {}, {});
    test({}, {0}, {0});

    return 0;
}
