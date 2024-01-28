#include "../inc.h"

class Solution {
   public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int m = s.size(), memo[m][1 << 10];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, bool, bool)> f = [&](int pos, int mask, bool limit,
                                                    bool is_num) -> int {
            if (pos == m) return is_num;
            if (!limit && is_num && memo[pos][mask] != -1) return memo[pos][mask];
            int ret = 0;
            if (!is_num) ret += f(pos + 1, mask, false, false);
            int up = limit ? s[pos] - '0' : 9;
            for (int d = 1 - is_num; d <= up; ++d) {
                if (((mask >> d) & 1) == 0) {
                    ret += f(pos + 1, mask | (1 << d), limit && d == up, true);
                }
            }
            if (!limit && is_num) memo[pos][mask] = ret;
            return ret;
        };
        return f(0, 0, true, false);
    }
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().countSpecialNumbers(n));
}

int main() {
    test(585362300, 4104810);
    test(20, 19);
    test(5, 5);
    test(135, 110);
    return 0;
}
