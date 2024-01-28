#include "../inc.h"

using LL = long long;

class Solution {
   public:
    long long minimumRemoval(vector<int>& beans) {
        LL ret = INT64_MAX, all = 0;
        sort(beans.begin(), beans.end());
        int n = beans.size();
        for (LL bi : beans) all += bi;
        for (int i = 0; i < n; ++i) {
            ret = min(ret, all - (LL)beans[i] * (n - 1 - i + 1));
        }

        return ret;
    }
};

void test(vector<int>&& beans, LL expect) {
    save4print(beans);
    assert_eq_ret(expect, Solution().minimumRemoval(beans));
}

int main() {
    test({4, 1, 6, 5}, 4);
    test({2, 10, 3, 2}, 7);
    return 0;
}