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
        print("ok.");
    } else {
        print("not ok.");
        print(head1);
        print(head2);
        print(ret);
        print();
    }
    releaseLinkedList(ret);
}

int main() {
    test({1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4});
    test({}, {}, {});
    test({}, {0}, {0});

    return 0;
}
