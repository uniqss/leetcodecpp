#include "../inc.h"

class Solution {
   public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int mask = 0;
        for (auto& ds : digits) mask |= (1 << (ds[0] - '0'));
        string s = to_string(n);
        int m = s.size(), memo[m];
        memset(memo, -1, sizeof(memo));
        function<int(int, bool, bool)> f = [&](int pos, bool limit, bool started) -> int {
            if (pos == m) return started;
            int ret = 0;
            if (!limit && started && memo[pos] != -1) return memo[pos];
            if (!started) ret += f(pos + 1, false, false);
            int up = limit ? s[pos] - '0' : 9;
            for (int d = 0; d <= up; ++d) {
                if ((mask >> d) & 1) ret += f(pos + 1, limit && d == up, true);
            }
            if (!limit && started) memo[pos] = ret;
            return ret;
        };
        return f(0, true, false);
    }
};

void test(vector<string>&& digits, int n, int expect) {
    save4print(digits, n);
    assert_eq_ret(expect, Solution().atMostNGivenDigitSet(digits, n));
}
int main() {
    test({"1", "3", "5", "7"}, 100, 20);
    test({"1", "4", "9"}, 1000000000, 29523);
    test({"7"}, 8, 1);
    return 0;
}