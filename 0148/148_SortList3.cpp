#include "../inc.h"

// 这样写更简洁
class Solution {
    struct NodeWrapper {
        ListNode* node;
        bool operator<(const NodeWrapper& rhs) const { return node->val > rhs.node->val; }
    };

   public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;
        priority_queue<NodeWrapper> q;
        while (head != nullptr) {
            q.push({head});
            head = head->next;
        }
        head = q.top().node, q.pop();
        ListNode* prev = head;
        while (!q.empty()) {
            prev->next = q.top().node, q.pop();
            prev = prev->next;
        }
        prev->next = nullptr;
        return head;
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
