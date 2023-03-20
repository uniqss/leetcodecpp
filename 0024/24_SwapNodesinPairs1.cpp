#include "../inc/inc.h"

/*
prev=>left=>right(=>savedNext)
exchange:
    savedNext = right->next
    left->next = savedNext
    right->next = left
    prev->next = right

prev=>right=>left
move:
oldPrev=>oldRight=>oldLeft=>left=>right
oldPrev=>oldRight=>prev=>left=>right

    prev = left
    left = savedNext
    right = left->next
*/
class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        ListNode temp;
        temp.next = head;
        ListNode* prev = &temp;
        ListNode* left = head;
        ListNode* right = left != nullptr ? left->next : nullptr;
        while (left != nullptr && right != nullptr) {
            ListNode* savedNext = right->next;
            left->next = savedNext;
            right->next = left;
            prev->next = right;

            prev = left;
            left = savedNext;
            right = left != nullptr ? left->next : nullptr;
        }
        return temp.next;
    }
};

void test(const std::vector<int>& vi, const vector<int>& expect) {
    ListNode* head = nullptr;
    Solution s;
    ListNode* ret = nullptr;

    head = constructList(vi);
    ret = s.swapPairs(head);
    auto retvals = list2vals(ret);
    if (retvals == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(vi);
        print(expect);
        print(retvals);
    }
    releaseLinkedList(ret);
}

int main(int argc, char const* argv[]) {
    test({}, {});
    test({1}, {1});
    test({1, 2}, {2, 1});
    test({1, 2, 3}, {2, 1, 3});
    test({1, 2, 3, 4}, {2, 1, 4, 3});
    test({1, 2, 3, 4, 5}, {2, 1, 4, 3, 5});

    return 0;
}
