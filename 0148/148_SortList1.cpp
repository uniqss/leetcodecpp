#include "../inc.h"

class Solution {
    struct NodeWrapper {
        ListNode* node;
        bool operator<(const NodeWrapper& rhs) const { return node->val > rhs.node->val; }
    };

   public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        priority_queue<NodeWrapper> pq;
        while (head != nullptr) {
            pq.push({head});
            head = head->next;
        }
        ListNode fake, *prev = &fake, *curr;
        while (!pq.empty()) {
            curr = pq.top().node;
            pq.pop();
            prev->next = curr;
            curr->next = nullptr;
            prev = curr;
        }
        return fake.next;
    }
};

void test(vector<int>&& listvals, const vector<int>& expect) {
    save4print(listvals);
    auto head = constructList(listvals);
    ListAutoReleaser _(head);
    auto ret = Solution().sortList(head);
    _.Append(ret);
    assert_eq_ret(expect, list2vals(ret));
}

int main() {
    test({4, 2, 1, 3}, {1, 2, 3, 4});
    test({-1, 5, 3, 4, 0}, {-1, 0, 3, 4, 5});
    test({}, {});
    return 0;
}
