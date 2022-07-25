#include "../inc.h"

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

void test_vi(const vector<int> &vi, const vector<int> &expect) {
    Solution s;
    ListNode *head = nullptr;
    ListNode *ret = nullptr;

    head = constructList(vi);
    ret = s.reverseList(head);
    // pLinkedList(ret);
    auto retval = list2vals(ret);
    if (retval == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(vi);
        print(expect);
        print(retval);
        print();
    }
    releaseLinkedList(ret);
}

int main(int argc, char const *argv[]) {
    test_vi({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
    test_vi({1, 2}, {2, 1});
    test_vi({}, {});

    return 0;
}
