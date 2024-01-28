#include "../inc.h"

using LL = long long;

class Solution {
    LL calc(LL n, int up, const string& suffix) {
        string s = to_string(n);
        int m = s.size(), slen = suffix.size();
        LL memo[m];
        memset(memo, -1, sizeof(memo));
        function<LL(int, bool)> f = [&](int pos, bool limit) -> LL {
            if (pos > m - slen) return 0;
            if (pos == m - slen) return 1;
            if (!limit && memo[pos] != -1) return memo[pos];
            LL ret = 0;
            for (int d = 0; d <= up; ++d) {
                ret += f(pos + 1, limit && d == up);
            }
            if (!limit) memo[pos] = ret;
            return ret;
        };
        return f(0, true);
    }

   public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        LL vstart = calc(start, limit, s), vfinish = calc(finish, limit, s);
        LL ret = vfinish - vstart;
        string starts = to_string(start);
        reverse(starts.begin(), starts.end());
        reverse(s.begin(), s.end());
        bool startvalid = true;
        for (int i = 0; i < starts.size(); ++i) {
            if (i < s.size() && starts[i] != s[i]) {
                startvalid = false;
                break;
            }
            if (starts[i] - '0' > limit) {
                startvalid = false;
                break;
            }
        }
        if (startvalid) ++ret;
        return ret;
    }
};

void test(LL start, LL finish, int limit, string s, LL expect) {
    save4print(start, finish, limit, s);
    assert_eq_ret(expect, Solution().numberOfPowerfulInt(start, finish, limit, s));
}

int main() {
    test(1, 6000, 4, "124", 5);
    test(15, 215, 6, "10", 2);
    test(1000, 2000, 4, "3000", 0);
    return 0;
}