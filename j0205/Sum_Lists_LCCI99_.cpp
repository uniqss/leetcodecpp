#include "../inc.h"

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {}
};

void test(const vector<int>& v1, const vector<int>& v2, const vector<int>& expect) {
    save4print(v1, v2);
    auto l1 = constructList(v1);
    auto l2 = constructList(v2);
    auto ret = Solution().addTwoNumbers(l1, l2);
    auto retval = list2vals(ret);
    ListAutoReleaser _(l1, l2, ret);
    assert_eq_ret(expect, retval);
}

int main() {
    // 看到这个测试用例，可以看出，即使用int64也放不下，我好像走错路了
    test({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
         {4, 6, 5}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 6});
    test({0}, {0}, {0});
    test({5}, {5}, {1, 0});
    test({6, 1, 7}, {2, 9, 5}, {9, 1, 2});
    test({3, 4, 2}, {4, 6, 5}, {8, 0, 7});  // 342 + 465 = 807
    return 0;
}