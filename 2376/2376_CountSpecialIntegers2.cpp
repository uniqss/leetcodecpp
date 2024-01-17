#include "../inc.h"

// 灵茶山经典写法
class Solution {
   public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int m = s.size(), memo[m][1<<10];
        memset(memo, -1, sizeof(memo));
        function<int(int,int,bool,bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m) return is_num;
            if (!is_limit && is_num && memo[i][mask] != -1) return memo[i][mask];
            int ret = 0;
            if (!is_num) ret += f(i + 1, mask, false, false);
            int up = is_limit ? s[i] - '0' : 9;
            for (int d = 1 - is_num; d <= up; ++d) {
                if (((mask >> d) & 1) == 0) {
                    ret += f(i + 1, mask | (1 << d), is_limit && d == up, true);
                }
            }
            if (!is_limit && is_num) memo[i][mask] = ret;
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
