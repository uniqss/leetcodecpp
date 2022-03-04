#include "../inc.h"

class Solution {
   public:
    ListNode *reverseList(ListNode *head) {
    }
};

void test_vi(const vector<int> &vi) {
    Solution s;
    ListNode *head = nullptr;
    ListNode *ret = nullptr;

    head = constructList(vi);
    ret = s.reverseList(head);
    pLinkedList(ret);
    releaseLinkedList(ret);
}

int main(int argc, char const *argv[]) {
    test_vi({1, 2, 3, 4, 5});
    test_vi({1, 2});

    return 0;
}
