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
        ListNode *prev = head, *next, *tmp;
        while (prev->next != nullptr) {
            next = prev->next->next;
            tmp = head;
            bool exist = false;
            while (tmp != prev->next) {
                if (tmp->val == prev->next->val) {
                    exist = true;
                    break;
                }
                tmp = tmp->next;
            }
            if (exist) {
                delete prev->next;
                prev->next = next;
            } else {
                prev = prev->next;
            }
        }

        return head;
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
