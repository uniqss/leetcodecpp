#include "../inc.h"

class Solution {
   public:
    ListNode* oddEvenList(ListNode* head) {}
};

void test(const vector<int>& arrin, const vector<int>& expect) {
    save4print(arrin);
    ListNode* head = constructList(arrin);
    ListAutoReleaser _(head);
    auto ret = Solution().oddEvenList(head);
    auto retval = list2vals(ret);
    assert_eq_ret(expect, retval);
}

int main() {
    test({1, 2, 3, 4, 5}, {1, 3, 5, 2, 4});
    test({2, 1, 3, 5, 6, 4, 7}, {2, 3, 6, 7, 1, 5, 4});
    return 0;
}
