#include "../inc.h"

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {}
};

void test(const vector<int>& headvals, const vector<int>& expect) {
    Solution so;
    ListNode* head = constructList(headvals);
    // ListAutoReleaser _(head);
    auto ret = so.deleteDuplicates(head);
    ListAutoReleaser _(ret);
    auto retvals = list2vals(ret);
    if (retvals == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(headvals);
        print(expect);
        print(retvals);
    }
}

int main() {
    test({1, 1, 2}, {1, 2});
    test({1, 1, 2, 3, 3}, {1, 2, 3});
    return 0;
}
