#include "../inc.h"

class Solution {
   public:
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) return head;
        vector<ListNode*> nodes = {head};
        head = head->next;
        auto bsearch = [&](int val) -> int {
            int l = 0, r = nodes.size() - 1, mid;
            if (nodes[l]->val < val) return -1;
            if (nodes[r]->val >= val) return r;
            while (l <= r) {
                mid = l + (r - l) / 2;
                if (nodes[mid]->val >= val) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            return r;
        };
        while (head != nullptr) {
            auto idx = bsearch(head->val);
            if (idx == -1) {
                for (auto node : nodes) delete node;
                nodes = {head};
            } else {
                nodes.erase(nodes.begin() + idx + 1, nodes.end());
                nodes.push_back(head);
            }
            head = head->next;
        }
        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes[nodes.size() - 1]->next = nullptr;
        return nodes[0];
    }
};

void test(vector<int>&& vs, const vector<int>& expect) {
    save4print(vs);
    auto head = constructList(vs);
    auto ret = Solution().removeNodes(head);
    ListAutoReleaser _(ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expect, retvals);
}

int main() {
    test({5, 2, 13, 3, 8}, {13, 8});
    test({1, 1, 1, 1}, {1, 1, 1, 1});
    return 0;
}
