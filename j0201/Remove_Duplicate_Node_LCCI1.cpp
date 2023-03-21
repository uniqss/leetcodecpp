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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr) return head;
        unordered_set<int> dict;
        ListNode fake(0, head);
        ListNode *prev = &fake, *next;
        while (prev != nullptr && prev->next != nullptr) {
            next = prev->next->next;
            if (dict.count(prev->next->val) > 0) {
                delete (prev->next);
                prev->next = next;
            } else {
                dict.insert(prev->next->val);
                prev = prev->next;
            }
        }

        return fake.next;
    }
};

void test(const vector<int>& vi, const vector<int>& expect) {
    auto list = constructList(vi);
    Solution so;
    auto ret = so.removeDuplicateNodes(list);
    auto retval = list2vals(ret);
    if (retval == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vi);
        print(expect);
        print(retval);
    }
    delete list;
}

int main() {
    test({1, 2, 3, 3, 2, 1}, {1, 2, 3});
    test({1, 1, 1, 1, 2}, {1, 2});
    return 0;
}
