#include "../inc.h"

class Solution {
   public:
    int pairSum(ListNode* head) {}
};

void test(const vector<int>& vals, int expect) {
    save4print(vals);
    auto head = constructList(vals);
    ListAutoReleaser _(head);
    auto ret = Solution().pairSum(head);
    assert_eq_ret(expect, ret);
}

int main() {
    test({5, 4, 2, 1}, 6);
    test({4, 2, 2, 3}, 7);
    test({1, 100000}, 100001);
    return 0;
}
