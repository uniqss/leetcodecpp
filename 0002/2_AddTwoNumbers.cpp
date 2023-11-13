#include "../inc.h"

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {}
};

void test(const vector<int>& v1, const vector<int>& v2, const vector<int>& expect) {
    save4print(v1);
    save4print(v2);
    auto l1 = constructList(v1);
    auto l2 = constructList(v2);
    Solution so;
    auto ret = so.addTwoNumbers(l1, l2);
    ListAutoReleaser _(l1, l2, ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expect, retvals);
}

int main() {
    test({2, 4, 3}, {5, 6, 4}, {7, 0, 8});
    test({0}, {0}, {0});
    test({9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1});
    return 0;
}
