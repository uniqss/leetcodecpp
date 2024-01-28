#include "../inc.h"

/*
时间复杂度：O(log(n)*10)
空间复杂度：O(log(n)*10)
*/
class Solution {
   public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.size(), memo[m][10];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, bool)> f = [&](int pos, int sum, bool limit) -> int {
            if (pos == m) return sum;
            if (!limit && memo[pos][sum] != -1) return memo[pos][sum];
            int ret = 0;
            int up = limit ? s[pos] - '0' : 9;
            for (int d = 0; d <= up; ++d) {
                int sadd = d == 1 ? 1 : 0;
                ret += f(pos + 1, sum + sadd, limit && d == up);
            }
            if (!limit) memo[pos][sum] = ret;
            return ret;
        };
        return f(0, 0, true);
    }
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().countDigitOne(n));
}

int main() {
    test(20, 12);
    test(13, 6);
    test(0, 0);
    return 0;
}