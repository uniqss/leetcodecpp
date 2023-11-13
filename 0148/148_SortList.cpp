#include "../inc.h"

class Solution {
   public:
    ListNode* sortList(ListNode* head) {}
};

void test(vector<int>&& listvals, const vector<int>& expect) {
    save4print(listvals);
    auto head = constructList(listvals);
    ListAutoReleaser _(head);
    auto ret = Solution().sortList(head);
    _.Append(ret);
    assert_eq_ret(expect, list2vals(ret));
}

int main() {
    test({4, 2, 1, 3}, {1, 2, 3, 4});
    test({-1, 5, 3, 4, 0}, {-1, 0, 3, 4, 5});
    test({}, {});
    return 0;
}
