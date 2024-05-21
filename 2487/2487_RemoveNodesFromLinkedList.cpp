#include "../inc.h"

class Solution {
   public:
    ListNode* removeNodes(ListNode* head) {}
};

void test(vector<int>&& vs, const vector<int>& expect) {
    save4print(vs);
    auto head = constructList(vs);
    auto ret = Solution().removeNodes(head);
    ListAutoReleaser _(ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expect, retvals);
}

int main() {
    test({5, 2, 13, 3, 8}, {13, 8});
    test({1, 1, 1, 1}, {1, 1, 1, 1});
    return 0;
}
