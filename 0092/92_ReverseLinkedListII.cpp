#include "../inc.h"

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {}
};

void test(const vector<int>& listvals, int left, int right, const vector<int>& expectvals) {
    save4print(listvals);
    save4print(left);
    save4print(right);
    ListNode* head = constructList(listvals);
    Solution so;
    auto ret = so.reverseBetween(head, left, right);
    ListAutoReleaser _(head, ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expectvals, retvals);
}

int main() {
    test({1, 2, 3, 4, 5}, 2, 4, {1, 4, 3, 2, 5});
    test({5}, 1, 1, {5});
    return 0;
}