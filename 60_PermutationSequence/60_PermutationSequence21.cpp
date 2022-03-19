#include "../inc.h"

class Solution {
   public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        --k;
        string ret(n, '0');
        int retIdx = 0;
        vector<int> valid(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            int order = k / factorial[n - i] + 1;
            for (int j = 1; j <= n; ++j) {
                order -= valid[j];
                if (!order) {
                    ret[retIdx++] += j;
                    valid[j] = 0;
                    break;
                }
            }
            k %= factorial[n - i];
        }
        return ret;
    }
};

void test(int n, int k, const string& expect) {
    Solution so;
    auto ret = so.getPermutation(n, k);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(n);
        praw(k);
        praw(expect);
        praw(ret);
    }
}

int main() {
    test(3, 3, "213");
    test(4, 9, "2314");
    test(3, 1, "123");
    return 0;
}
