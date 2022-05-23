#include "../inc.h"

/*
中文官方 题解
这样写代码至少不是个好习惯，这里利用了 1 <= n <= sz 工程中更推荐写出即使 n=0 或者 n > sz 时也不会崩溃的代码，或者至少在进来的时候 check 一下 n
*/

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *slow = dummy, *fast = head;
        for (int i = 0; i < n && fast != nullptr; ++i) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = slow->next->next;
        delete fast;
        slow = dummy->next;
        delete dummy;
        return slow;
    }
};

void test(const vector<int>& lval, int n, const vector<int>& expect) {
    Solution so;
    auto list = constructList(lval);
    auto ret = so.removeNthFromEnd(list, n);

    auto retval = list2vals(ret);
    if (retval == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(lval);
        praw(n);
        pvraw(expect);
        pvraw(retval);
        pnewline();
    }

    releaseLinkedList(ret);
}

int main() {
    test({1, 2, 3, 4, 5}, 2, {1, 2, 3, 5});
    test({1}, 1, {});
    test({1, 2}, 1, {1});
    return 0;
}
