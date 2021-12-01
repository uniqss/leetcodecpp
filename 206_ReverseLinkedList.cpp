#include "stl.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode *reverseList1(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr) {
            ListNode *savedNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = savedNext;
        }
        return prev;
    }
    //　不推荐这样写，上面的写法更容易理解
    ListNode *reverseList2(ListNode *head) {
        ListNode *prev = nullptr;
        while (head != nullptr) {
            ListNode *savedNext = head->next;
            head->next = prev;
            prev = head;
            head = savedNext;
        }
        return prev;
    }
    // 两脚走路，是否能空间换时间？
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *left = head;
        ListNode *right = head->next;
        ListNode *tempNext = nullptr;
        left->next = nullptr;
        while (true) {
            // move left ahead
            if (right != nullptr) {
                tempNext = right->next;
                right->next = left;
                if (tempNext == nullptr) return right;
                left = tempNext;
            }

            // move right ahead
            if (left != nullptr) {
                tempNext = left->next;
                left->next = right;
                if (tempNext == nullptr) return left;
                right = tempNext;
            }
        }
    }
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
void plist(const ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void freelist(ListNode *head) {
    ListNode *temp = nullptr;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void test_vi(const vector<int> &vi) {
    Solution s;
    ListNode *head = nullptr;
    ListNode *ret = nullptr;

    head = constructList(vi);
    ret = s.reverseList(head);
    plist(ret);
    freelist(ret);
}

int main(int argc, char const *argv[]) {
    test_vi({1, 2, 3, 4, 5});
    test_vi({1, 2});

    return 0;
}
