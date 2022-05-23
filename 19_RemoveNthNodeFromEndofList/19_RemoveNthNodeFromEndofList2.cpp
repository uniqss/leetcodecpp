#include "../inc.h"

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode ofake(0, head), *fake = &ofake;  // 这样写天塌地崩都不会内存没回收
        ListNode *slow = fake, *fast = fake;
        // n = 2 需要移动 3次   n+1次
        while (n-- >= 0 && fast != nullptr) {
            fast = fast->next;
        }
        if (n > 0) return head;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        auto tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return fake->next;
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
