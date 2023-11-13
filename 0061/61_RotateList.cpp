#include "../inc.h"

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {}
};

void test(const vector<int>& listvals, int k, const vector<int>& expectvals) {
    save4print(listvals);
    save4print(k);
    ListNode* head = constructList(listvals);
    Solution so;
    auto ret = so.rotateRight(head, k);
    ListAutoReleaser _(head, ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expectvals, retvals);
}

int main() {
    test({1, 2}, 1, {2, 1});
    test({1, 2, 3, 4, 5}, 2, {4, 5, 1, 2, 3});
    test({0, 1, 2}, 4, {2, 0, 1});
    return 0;
}
