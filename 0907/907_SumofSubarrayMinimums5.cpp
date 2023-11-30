#include "../inc.h"

class Solution {
   public:
    int sumSubarrayMins(vector<int>& arr) {
        // 队列被干空的概率非常低，平均会越来越长，所以预计算会提速
        vector<pair<int, int>> q(arr.size());
        int qsize = 0;
        int64_t ret = 0, mod = 1e9 + 7, qcurr = 0;
        for (int a : arr) {
            int del = 0;
            while (qsize > 0 && q[qsize - 1].first >= a) {
                del += q[qsize - 1].second + 1, qcurr -= (int64_t)q[qsize - 1].first * (q[qsize - 1].second + 1),
                    --qsize;
            }
            q[qsize++] = {a, del};
            qcurr += (int64_t)a * (del + 1);
            ret += qcurr;
            ret %= mod;
        }
        return ret;
    }
};

void test(vector<int>&& arr, int expect) {
    save4print(arr);
    assert_eq_ret(expect, Solution().sumSubarrayMins(arr));
}

int main() {
    test({3, 1, 2, 4}, 17);
    test({11, 81, 94, 43, 3}, 444);
    return 0;
}
