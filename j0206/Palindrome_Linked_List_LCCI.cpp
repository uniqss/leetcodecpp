#include "../inc.h"

class Solution {
   public:
    bool isPalindrome(ListNode* head) {}
};

void test(const vector<int>& vi, bool expect) {
    save4print(vi);
    auto list = constructList(vi);
    ListAutoReleaser _(list);
    assert_eq_ret(expect, Solution().isPalindrome(list));
}

int main() {
    test({1, 2}, false);
    test({1, 2, 1}, true);
    test({1, 2, 2, 1}, true);
    test({0, 2, 2, 1}, false);
    return 0;
}
