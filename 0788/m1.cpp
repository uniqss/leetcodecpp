#include "../inc.h"

class Solution {
   public:
    int rotatedDigits(int n) {
        vector<int> dict = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
        string s = to_string(n);
        int m = s.size(), memo[m][2];
        memset(memo, -1, sizeof(memo));
        function<int(int, bool, bool)> f = [&](int pos, bool hasDigit, bool limit) -> int {
            if (pos == m) return hasDigit;
            if (!limit && memo[pos][hasDigit] != -1) return memo[pos][hasDigit];
            int ret = 0;
            int up = limit ? s[pos] - '0' : 9;
            for (int d = 0; d <= up; ++d) {
                if (dict[d] >= 0) {
                    bool currHasDigit = dict[d] > 0;
                    ret += f(pos + 1, hasDigit || currHasDigit, limit && d == up);
                }
            }
            return ret;
        };
        return f(0, false, true);
    }
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().rotatedDigits(n));
}

int main() {
    test(10, 4);
    test(1, 0);
    test(2, 1);
    return 0;
}