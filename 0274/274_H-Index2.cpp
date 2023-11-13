#include "../inc.h"

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        // 这样搞能搞成O(n)，本质上是个hash
        int n = citations.size();
        vector<int> n2count(n + 1);
        for (int c : citations) ++n2count[min(c, n)];
        int total = 0;
        for (int i = n; i >= 0; --i) {
            total += n2count[i];
            if (i <= total) {
                return i;
            }
        }
        return total;
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
    test({3, 0, 6, 1, 5}, 3);
    test({1, 3, 1}, 1);
    return 0;
}
