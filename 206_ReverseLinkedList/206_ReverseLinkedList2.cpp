#include "../inc.h"

class Solution {
   public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *curr = head, *next = head->next;
        while (next != nullptr) {
            ListNode *nnext = next->next;
            next->next = curr;
            curr = next;
            next = nnext;
        }
        head->next = nullptr;
        return curr;
    }
};

void test_vi(const vector<int> &vi, const vector<int> &expect) {
    Solution s;
    ListNode *head = nullptr;
    ListNode *ret = nullptr;

    head = constructList(vi);
    ret = s.reverseList(head);
    // pLinkedList(ret);
    auto retval = list2vals(ret);
    if (retval == expect) {
        praw("ok");
    } else {
        praw("not ok.");
        pvraw(vi);
        pvraw(expect);
        pvraw(retval);
        pnewline();
    }
    releaseLinkedList(ret);
}

int main(int argc, char const *argv[]) {
    test_vi({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
    test_vi({1, 2}, {2, 1});
    test_vi({}, {});

    return 0;
}
