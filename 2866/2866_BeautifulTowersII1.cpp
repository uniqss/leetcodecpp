#include "../inc.h"

class Solution {
   public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> ml(n), mr(n);
        // deque<pair<idx, delcount>>
        deque<pair<int, int>> ql, qr;
        long long vl = 0, vr = 0;
        for (int i = 0; i < n; ++i) {
            int mi = maxHeights[i], delcount = 0;
            while (!ql.empty() && maxHeights[ql.back().first] >= mi) {
                vl -= (long long)maxHeights[ql.back().first] * (ql.back().second + 1);
                delcount += ql.back().second + 1;
                ql.pop_back();
            }
            ql.emplace_back(i, delcount);
            vl += (long long)mi * (delcount + 1);
            ml[i] = vl;
        }
        for (int i = n - 1; i >= 0; --i) {
            int mi = maxHeights[i], delcount = 0;
            while (!qr.empty() && maxHeights[qr.back().first] >= mi) {
                vr -= (long long)maxHeights[qr.back().first] * (qr.back().second + 1);
                delcount += qr.back().second + 1;
                qr.pop_back();
            }
            qr.emplace_back(i, delcount);
            vr += (long long)mi * (delcount + 1);
            mr[i] = vr;
        }
        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, ml[i] + mr[i] - maxHeights[i]);
        }
        return ret;
    }
};

void test(vector<int>&& maxHeights, long long expect) {
    save4print(maxHeights);
    assert_eq_ret(expect, Solution().maximumSumOfHeights(maxHeights));
}

int main() {
    test({6, 5, 2, 1, 5, 4, 4, 2}, 19);
    test({3, 5, 3, 5, 1, 5, 4, 4, 4}, 22);
    test({5, 3, 4, 1, 1}, 13);
    test({6, 5, 3, 9, 2, 7}, 22);
    test({3, 2, 5, 5, 2, 3}, 18);
    return 0;
}
