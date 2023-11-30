#include "../inc.h"

class Solution {
   public:
    ListNode *reverseList(ListNode *head) {}
};

void test_vi(const vector<int> &vi, const vector<int> &expect) {
    save4print(vi);
    auto head = constructList(vi);
    auto ret = Solution().reverseList(head);
    ListAutoReleaser _(ret);
    auto retval = list2vals(ret);
    assert_eq_ret(expect, retval);
}

int main(int argc, char const *argv[]) {
    test_vi({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
    test_vi({1, 2}, {2, 1});
    test_vi({}, {});

    return 0;
}
