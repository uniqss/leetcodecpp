#include "../inc.h"

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {}
};

void test(const vector<int>& lval, int n, const vector<int>& expect) {
    save4print(lval);
    save4print(n);
    Solution so;
    auto list = constructList(lval);
    auto ret = so.removeNthFromEnd(list, n);
    auto retval = list2vals(ret);
    ListAutoReleaser _(ret);
    assert_eq_ret(expect, retval);
}

int main() {
    test({1, 2, 3, 4, 5}, 2, {1, 2, 3, 5});
    test({1}, 1, {});
    test({1, 2}, 1, {1});
    return 0;
}
