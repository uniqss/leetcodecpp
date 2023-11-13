#include "../inc.h"

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode fake, *prev = &fake;
        while (true) {
            int vmin = INT_MAX;
            int idxmin = -1;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] == nullptr) continue;
                if (lists[i]->val < vmin) {
                    vmin = lists[i]->val;
                    idxmin = i;
                }
            }
            if (idxmin == -1) break;
            prev->next = lists[idxmin];
            lists[idxmin] = lists[idxmin]->next;
            prev = prev->next;
        }

        return fake.next;
    }
};

void test(vector<vector<int>>&& listvals, const vector<int>& expect) {
    save4print(listvals);
    vector<ListNode*> lists;
    ListAutoReleaser _;
    for (int i = 0; i < listvals.size(); ++i) {
        lists.emplace_back(constructList(listvals[i]));
    }
    _.Append(lists);
    auto ret = Solution().mergeKLists(lists);
    _.Append(ret);
    assert_eq_ret(expect, list2vals(ret));
}

int main() {
    test({{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6});
    test({}, {});
    test({{}}, {});
    return 0;
}
