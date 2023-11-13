#include "../inc.h"

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {}
};

void test(const vector<int>& headvals, const vector<int>& expect) {
    ListNode* head = constructList(headvals);
    auto ret = Solution().deleteDuplicates(head);
    ListAutoReleaser _(ret);
    assert_eq_ret(expect, list2vals(ret));
}

int main() {
    test({1, 1, 2}, {1, 2});
    test({1, 1, 2, 3, 3}, {1, 2, 3});
    return 0;
}
