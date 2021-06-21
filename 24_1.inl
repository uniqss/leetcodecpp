
// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};



class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* pRet = head->next;
		ListNode* pStepEnd = head->next->next;
		ListNode* pCurr = head;
		ListNode* pNext = pCurr->next;
		ListNode* pPrev = pCurr;
		while (true)
		{
			pPrev->next = pNext;

			pNext->next = pCurr;
			pCurr->next = pStepEnd;
			if (pStepEnd == nullptr)
			{
				break;
			}
			if (pStepEnd->next == nullptr)
			{
				break;
			}
			pPrev = pCurr;
			pCurr = pStepEnd;
			pNext = pCurr->next;
			if (pNext == nullptr)
			{
				break;
			}
			pStepEnd = pNext->next;
		}

		return pRet;
	}
};
