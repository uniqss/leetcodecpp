#include "../inc.h"

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k <= 1) return head;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (true) {
            head = prev->next;
            ListNode* tail = prev;
            for (int i = 0; i < k; ++i) {
                if (tail == nullptr || tail->next == nullptr) return dummy.next;
                tail = tail->next;
            }
            ListNode* next = tail->next;
            // reverse
            ListNode* rprev = head;
            ListNode* rcurr = rprev->next;
            while (rcurr != next) {
                ListNode* rnext = rcurr->next;
                rcurr->next = rprev;
                rprev = rcurr;
                rcurr = rnext;
            }
            head->next = next;
            prev->next = tail;
            prev = head;
        }
        return dummy.next;
    }
};

void test(const std::vector<int>& vi, int k, const vector<int>& expect) {
    ListNode* head = nullptr;
    Solution s;
    ListNode* ret = nullptr;

    head = constructList(vi);
    ret = s.reverseKGroup(head, k);
    auto retval = list2vals(ret);
    if (retval == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(vi);
        print(k);
        print(expect);
        print(retval);
        print();
    }
    releaseLinkedList(ret);
}

int main(int argc, char const* argv[]) {
    test({1, 2, 3, 4, 5, 6}, 2, {2, 1, 4, 3, 6, 5});
    test({1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5});
    test({1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5});
    test({1, 2, 3, 4, 5}, 1, {1, 2, 3, 4, 5});
    test({1, 2}, 2, {2, 1});
    test({1}, 1, {1});
    return 0;
}
