#include "../inc.h"

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {}
};

void test(const vector<int>& listvals, const vector<int>& expectvals) {
    save4print(listvals);
    ListNode* head = constructList(listvals);
    auto ret = Solution().deleteDuplicates(head);
    ListAutoReleaser _(ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expectvals, retvals);
}

int main() {
    test({1, 2, 3, 3, 4, 4, 5}, {1, 2, 5});
    test({1, 1, 1, 2, 3}, {2, 3});
    return 0;
}
