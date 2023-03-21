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
    int kthToLast(ListNode* head, int k) {
        /*
        1 2 3 4 5 null  2
        h   p
              h   p
        */
        if (head == nullptr) return -1;
        ListNode* p = head;
        for (int i = 0; i < k; ++i) {
            if (p == nullptr) return -1;
            p = p->next;
        }
        while (p != nullptr) {
            p = p->next;
            head = head->next;
        }
        return head->val;
    }
};

void test(const vector<int>& vi, int k, int expect) {
    auto list = constructList(vi);
    Solution so;
    auto ret = so.kthToLast(list, k);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(vi);
        print(k);
        print(expect);
        print(ret);
        print();
    }
    releaseLinkedList(list);
}

int main() {
    test({1, 2, 3, 4, 5}, 2, 4);
    return 0;
}
