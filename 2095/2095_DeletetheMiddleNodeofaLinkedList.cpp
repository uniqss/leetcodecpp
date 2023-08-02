#include "../inc.h"

class Solution {
   public:
    ListNode* deleteMiddle(ListNode* head) {}
};

void test(const vector<int>& inarr, const vector<int>& expect) {
    auto head = constructList(inarr);
    Solution so;
    auto ret = so.deleteMiddle(head);
    ListAutoReleaser _(ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expect, retvals);
    print(inarr);
}

int main() {
    test({1, 3, 4, 7, 1, 2, 6}, {1, 3, 4, 1, 2, 6});
    test({1, 2, 3, 4}, {1, 2, 4});
    test({2, 1}, {2});
    test({2}, {});
    return 0;
}
