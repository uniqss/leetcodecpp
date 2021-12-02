#include "stl.h"

/*

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode temp(0, head);
        ListNode* prev = &temp;
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr)
        {
            prev->next = curr->next;
            prev = 
        }
        return temp.next;
    }
};