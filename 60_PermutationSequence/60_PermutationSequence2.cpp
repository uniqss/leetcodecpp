#include "../inc.h"

/*
中文官方题解，先组织 [1, 1, 2, 6, 24, 120, 720, 5040, 40320, ......] 的阶乘数组
n位有n!种排列
n-1位有(n-1)!种排列
所以根据k除以(n-1)!就能算出第一位是个啥
同样的算法再往后一位一位计算出最终结果
*/
class Solution {
   public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        --k;
        string ret;
        vector<int> valid(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            int order = k / factorial[n - i] + 1;
            for (int j = 1; j <= n; ++j) {
                order -= valid[j];
                if (!order) {
                    ret += (j + '0');
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
        print("ok.");
    } else {
        print("not ok.");
        print(n);
        print(k);
        print(expect);
        print(ret);
    }
}

int main() {
    test(3, 3, "213");
    test(4, 9, "2314");
    test(3, 1, "123");
    return 0;
}
