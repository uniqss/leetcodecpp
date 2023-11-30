#include "../inc.h"

class Solution {
   public:
    int sumSubarrayMins(vector<int>& arr) {
        /*
        冷静的想一想这个题，假设前面已经有数组 [0...x - 1]了，现在加入了一个arr[x]进来，这个时候ret需要加哪些：
        ret += arr[x]
        ret += min(arr[x-1...x])
        ret += min(arr[x-2...x])
        所以这个题应该是个单调栈或者是单调队列
        */
        vector<pair<int, int>> q(arr.size());
        int qsize = 0;
        int64_t ret = 0, mod = 1e9 + 7;
        for (int a : arr) {
            int del = 0;
            while (qsize > 0 && q[qsize - 1].first >= a) {
                del += q[qsize - 1].second + 1, --qsize;
            }
            q[qsize++] = {a, del};
            for (int i = 0; i < qsize; ++i) {
                ret += (int64_t)q[i].first * (q[i].second + 1);
                ret %= mod;
            }
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
