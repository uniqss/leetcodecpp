#include "../inc.h"

class Solution {
   public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        --k;
        vector<char> remain(n);
        for (int i = 0; i < n; ++i) {
            remain[i] = '1' + i;
        }

        for (int i = 0; i < n; ++i) {
            int remain_idx = k / factorial[n - 1 - i];
            k %= factorial[n - 1 - i];
            ret += remain[remain_idx];
            std::move(remain.begin() + remain_idx + 1, remain.end() - i, remain.begin() + remain_idx);
        }
        return ret;
    }
};

void test(int n, int k, const string& expect) {
    save4print(n, k);
    assert_eq_ret(expect, Solution().getPermutation(n, k));
}

int main() {
    test(3, 3, "213");
    test(4, 9, "2314");
    test(3, 1, "123");
    return 0;
}
