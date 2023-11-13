#include "../inc.h"

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {}
};

void test(const std::vector<int>& vi, const vector<int>& expect) {
    save4print(vi);
    ListNode *head = nullptr, *ret = nullptr;
    head = constructList(vi);
    ret = Solution().swapPairs(head);
    ListAutoReleaser _(head, ret);
    assert_eq_ret(expect, list2vals(ret));
}

int main(int argc, char const* argv[]) {
    test({}, {});
    test({1}, {1});
    test({1, 2}, {2, 1});
    test({1, 2, 3}, {2, 1, 3});
    test({1, 2, 3, 4}, {2, 1, 4, 3});
    test({1, 2, 3, 4, 5}, {2, 1, 4, 3, 5});

    return 0;
}
