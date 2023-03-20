#include "../inc/inc.h"

// code optimize.
class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode *left = nullptr, *right = nullptr;
        while (prev->next != nullptr && prev->next->next != nullptr) {
            left = prev->next;
            right = left->next;
            ListNode* next = right->next;
            prev->next = right;
            right->next = left;
            left->next = next;
            prev = left;
        }

        return dummy.next;
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
