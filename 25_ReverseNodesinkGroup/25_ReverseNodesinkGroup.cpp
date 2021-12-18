#include "../stl.h"

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    }
};

void test(const std::vector<int>& vi, int k) {
    ListNode* head = nullptr;
    Solution s;
    ListNode* ret = nullptr;

    head = constructList(vi);
    pLinkedList(head);
    praw(k);
    ret = s.reverseKGroup(head, k);
    pLinkedList(ret);
    releaseLinkedList(ret);
    pnewline();
}

int main(int argc, char const* argv[]) {
    test({1, 2, 3, 4, 5, 6}, 2);
    test({1, 2, 3, 4, 5}, 2);
    test({1, 2, 3, 4, 5}, 3);
    test({1, 2, 3, 4, 5}, 1);
    test({1, 2}, 2);
    test({1}, 1);
    return 0;
}