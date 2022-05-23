#include "../inc.h"


class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* fake = new ListNode(0, head);
        head = fake;
        ListNode* tmp;
        while (head != nullptr && head->next != nullptr) {
            if (head->next->val == val) {
                tmp = head->next;
                head->next = head->next->next;
                delete tmp;
            } else {
                head = head->next;
            }
        }

        head = fake->next;
        delete fake;
        return head;
    }
};


void test(const vector<int>& list_vals, int val, const vector<int>&& expect) {
    Solution so;
    ListNode* list = constructList(list_vals);
    auto ret = so.removeElements(list, val);
    auto lexpect = constructList(expect);
    if (listEqual(ret, lexpect)) {
        praw("ok");
    } else {
        praw("not ok.");
        pvraw(list_vals);
        praw(val);
        pLinkedList(lexpect);
        pLinkedList(ret);
        pnewline();
    }
    releaseLinkedList(ret);
    releaseLinkedList(lexpect);
}

int main() {
    test({1, 2, 6, 3, 4, 5, 6}, 6, {1, 2, 3, 4, 5});
    test({}, 1, {});
    test({7, 7, 7, 7}, 7, {});
    return 0;
}
