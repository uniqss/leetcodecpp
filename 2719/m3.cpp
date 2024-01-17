#include "../inc.h"

class Solution {
    int mod = 1e9 + 7;

   public:
    int calc(const string& s, int min_sum, int max_sum) {
        int m = s.size(), memo[m][199];
        memset(memo, -1, sizeof(memo));
        /*
        @param under if the current sequence is smaller than the given upperbound
        a b c d e f ...
        a b c d 当前选择序列每位都到了顶格满了，叫做 not under。
                    否则就是under，under进来为true时up到顶
        */
        function<int(int, int, bool)> f = [&](int pos, int sum, bool under) -> int {
            if (sum > max_sum) return 0;
            if (pos == m) return sum >= min_sum;
            if (under && memo[pos][sum] != -1) return memo[pos][sum];
            int ret = 0;
            int up = under ? 9 : s[pos] - '0';
            for (int d = 0; d <= up; ++d) {
                ret += f(pos + 1, sum + d, under || d < up);
                ret %= mod;
            }
            if (under) memo[pos][sum] = ret;
            return ret;
        };
        return f(0, 0, false);
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int ret = calc(num2, min_sum, max_sum) - calc(num1, min_sum, max_sum) + mod;
        int sum1 = 0;
        for (char c : num1) sum1 += c - '0';
        if (sum1 >= min_sum && sum1 <= max_sum) ++ret;
        ret %= mod;
        return ret;
    }
};

void test(string num1, string num2, int min_sum, int max_sum, int expect) {
    save4print(num1, num2, min_sum, max_sum);
    assert_eq_ret(expect, Solution().count(num1, num2, min_sum, max_sum));
}

int main() {
    test("4179205230", "7748704426", 8, 46, 883045899);
    test("1", "12", 1, 8, 11);
    test("1", "5", 1, 5, 5);
    return 0;
}