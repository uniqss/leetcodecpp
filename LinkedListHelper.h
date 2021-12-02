#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode *constructList(const vector<int> &vi) {
    if (vi.empty()) {
        return new ListNode();
    }
    ListNode *next = nullptr;
    ListNode *curr = nullptr;
    for (int i = vi.size() - 1; i >= 0; --i) {
        curr = new ListNode(vi[i], next);
        next = curr;
    }
    return curr;
}

void pLinkedList(const ListNode* head) {
    while (head != nullptr)
    {
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}

void releaseLinkedList(ListNode* head) {
    ListNode* next = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        delete head;
        head = next;
    }
}


