#include "../inc.h"


class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {}
};


void test(const vector<int>& list_vals, int val, const vector<int>&& expect) {
    Solution so;
    ListNode* list = constructList(list_vals);
    auto ret = so.removeElements(list, val);
    auto lexpect = constructList(expect);
    if (listEqual(ret, lexpect)) {
        print("ok");
    } else {
        print("not ok.");
        print(list_vals);
        print(val);
        print(lexpect);
        print(ret);
        print();
    }
    releaseLinkedList(ret);
    releaseLinkedList(lexpect);
}

int main() {
    test({1, 2, 6, 3, 4, 5, 6}, 6, {1, 2, 3, 4, 5});
    test({}, 1, {});
    test({7, 7, 7, 7}, 7, {});
    return 0;
}
