#include "../inc.h"

class Solution {
    const int mod = 1e9 + 7;

   public:
    int calc(const string& num, int min_sum, int max_sum) {
        int m = num.size(), memo[m][401];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, bool)> f = [&](int i, int sum, bool is_limit) -> int {
            if (sum > max_sum) return 0;
            if (i == m) {
                return sum >= min_sum;
            }
            if (!is_limit && memo[i][sum] != -1) return memo[i][sum];
            int ret = 0;
            int up = is_limit ? num[i] - '0' : 9;
            for (int d = 0; d <= up; ++d) {
                ret += f(i + 1, sum + d, is_limit && d == up);
                ret %= mod;
            }
            if (!is_limit) memo[i][sum] = ret;
            return ret;
        };
        return f(0, 0, true);
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n2 = calc(num2, min_sum, max_sum), n1 = calc(num1, min_sum, max_sum);
        int sum1 = 0;
        for (char c : num1) sum1 += c - '0';
        if (sum1 >= min_sum && sum1 <= max_sum) return (n2 - n1 + 1 + mod) % mod;
        return (n2 + mod - n1) % mod;
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