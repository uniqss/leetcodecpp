#include "../inc.h"

// 时间复杂度：9log(n) = log(n)
// 空间复杂度：2log(n) = log(n)
class Solution {
   public:
    int rotatedDigits(int n) {
        vector<int> dict = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
        string s = to_string(n);
        int m = s.size(), memo[m][2];
        memset(memo, -1, sizeof(memo));
        function<int(int, bool, bool)> f = [&](int pos, bool valid, bool limit) -> int {
            if (pos == m) return valid;
            if (!limit && memo[pos][valid] != -1) return memo[pos][valid];
            int ret = 0;
            int up = limit ? s[pos] - '0' : 9;
            for (int d = 0; d <= up; ++d) {
                if (dict[d] >= 0) {
                    ret += f(pos + 1, valid || dict[d] > 0, limit && d == up);
                }
            }
            memo[pos][valid] = ret;
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