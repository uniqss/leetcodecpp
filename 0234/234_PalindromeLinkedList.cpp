#include "../inc.h"


class Solution {
   public:
    bool isPalindrome(ListNode* head) {}
};

void test(const vector<int>& headvals, bool expect) {
    ListNode* head = constructList(headvals);
    ListAutoReleaser _(head);
    Solution so;
    auto ret = so.isPalindrome(head);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(headvals);
        print(expect);
        print(ret);
    }
}

int main() {
    test({1, 2, 3, 1}, false);
    test({1, 2, 2, 1}, true);
    test({1, 2}, false);
    test({1, 2, 1}, true);
    test({1, 2, 2}, false);
    return 0;
}
