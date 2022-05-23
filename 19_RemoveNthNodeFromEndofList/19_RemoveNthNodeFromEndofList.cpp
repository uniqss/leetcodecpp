#include "../inc.h"

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {}
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