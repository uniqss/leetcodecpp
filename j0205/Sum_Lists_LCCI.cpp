#include "../inc.h"

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
        6 1 7   2 9 5   9 1 2
        617 + 295 = 912
        */
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        int size1 = 0;
        int size2 = 0;
        ListNode* tmp = l1;
        while (tmp != nullptr) {
            tmp = tmp->next;
            ++size1;
        }
        tmp = l2;
        while (tmp != nullptr) {
            tmp = tmp->next;
            ++size2;
        }

        int overflow = 0;
        ListNode fake;
        ListNode* head = &fake;
        int size = max(size1, size2);
        while (size1 > 0 || size2 > 0 || overflow > 0) {
            int val = overflow;
            if (size1 > 0 && size == size1) {
                val += l1->val;
                l1 = l1->next;
                --size1;
            }
            if (size2 > 0 && size == size2) {
                val += l2->val;
                l2 = l2->next;
                --size2;
            }
            --size;
            ListNode* curr = new ListNode(val % 10, head->next);
            overflow = val / 10;
            head->next = curr;
        }
        return fake.next;
    }
};

void test(const vector<int>& v1, const vector<int>& v2, const vector<int>& expect) {
    auto l1 = constructList(v1);
    auto l2 = constructList(v2);
    Solution so;
    auto ret = so.addTwoNumbers(l1, l2);
    auto retval = list2vals(ret);
    if (retval == expect) {
        print("ok");
    } else {
        print("not ok");
        print(v1);
        print(v2);
        print(expect);
        print(retval);
        print();
    }
    releaseLinkedList(l1);
    releaseLinkedList(l2);
    releaseLinkedList(ret);
}

int main() {
    // 看到这个测试用例，可以看出，即使用int64也放不下，我好像走错路了
    test({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {4, 6, 5},
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 6});
    test({0}, {0}, {0});
    test({5}, {5}, {1, 0});
    test({6, 1, 7}, {2, 9, 5}, {9, 1, 2});
    test({3, 4, 2}, {4, 6, 5}, {8, 0, 7});  // 342 + 465 = 807
    return 0;
}