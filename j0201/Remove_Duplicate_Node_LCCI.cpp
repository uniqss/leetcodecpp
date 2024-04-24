#include "../inc.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* removeDuplicateNodes(ListNode* head) {}
};

void test(const vector<int>& vi, const vector<int>& expect) {
    save4print(vi);
    auto list = constructList(vi);
    auto ret = Solution().removeDuplicateNodes(list);
    auto retval = list2vals(ret);
    assert_eq_ret(expect, retval);
    releaseLinkedList(list);
}

int main() {
    test({1, 2, 3, 3, 2, 1}, {1, 2, 3});
    test({1, 1, 1, 1, 2}, {1, 2});
    return 0;
}
