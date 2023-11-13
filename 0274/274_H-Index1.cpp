#include "../inc.h"

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        priority_queue<int, vector<int>, std::less<int>> pq(citations.begin(), citations.end());
        int count = 0, idx = citations.size();
        while (!pq.empty()) {
            if (count >= pq.top()) return count;
            ++count;
            pq.pop();
        }
        return count;
    }
};

void test(vector<int>&& citations, int expect) {
    auto p1 = citations;
    Solution so;
    auto ret = so.hIndex(citations);
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({1}, 1);
    test({2}, 1);
    test({3, 0, 6, 1, 5}, 3);
    test({1, 3, 1}, 1);
    return 0;
}
