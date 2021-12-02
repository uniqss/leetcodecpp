#include "stl.h"

/*
prev=>n1=>...=>nk(=>savedNext)
exchange:
    savedNext = nk->next
    reverse n1...nk
        nprev, ncurr
            nSavedNext = ncurr->next
            ncurr->next = nprev
            
            nprev = ncurr
            ncurr = nSavedNext
    prev->next = n1

prev=>nk=>...->n1
move:
oldPrev=>nk=>...=>n1=>savedNext
oldPrev=>oldnk=>...=>oldn1(prev)=>savedNext(n1)

    prev = n1
    n1 = savedNext
    here we don't save right.
*/

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    }
};