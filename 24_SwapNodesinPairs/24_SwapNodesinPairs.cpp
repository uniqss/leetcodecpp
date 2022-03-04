#include "../inc.h"

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
    }
};

void test(const std::vector<int>& vi) {
    ListNode* head = nullptr;
    Solution s;
    ListNode* ret = nullptr;

    head = constructList(vi);
    pLinkedList(head);
    ret = s.swapPairs(head);
    pLinkedList(ret);
    releaseLinkedList(ret);
}

int main(int argc, char const* argv[]) {
    test({});
    test({1});
    test({1, 2});
    test({1, 2, 3});
    test({1, 2, 3, 4});
    test({1, 2, 3, 4, 5});

    return 0;
}
