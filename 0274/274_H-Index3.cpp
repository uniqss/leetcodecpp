#include "../inc.h"

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        // 二分的又一次应用。这个算法的优点在于，它把内存成功的搞到了O(1)
        int n = citations.size(), l = 1, r = n, mid, ret = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            int count = 0;
            for (int c : citations) count += c >= mid ? 1 : 0;
            if (count < mid) {
                r = mid - 1;
            } else {
                ret = max(ret, mid);
                l = mid + 1;
            }
        }

        return ret;
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
