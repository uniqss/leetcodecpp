#include "../inc.h"

/*
基于官方的思路，自己造的轮子，和人的思维更接近，同时如果题目这样变一下的话，会更容易处理：
给定一个数组，从小到大，unique，求取第k个的排列。之所以更容易处理是官方解法取巧有点过度。这里直接把这个数组填入remain，后续处理逻辑几乎一致，填入某位，前移一格，再填入下一位
如果这里面的元素是有重的，，，算法如何写？只能backtrace?因为我们这里的思路都是在取巧，基于一个前提：n-1位的全部可能的数量是(n-1)! 从而一位一位锁定。有重时这个前提不成立
*/

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
        std::generate(remain.begin(), remain.end(), [_n = '0']() mutable { return ++_n; });
        for (int i = 0; i < n; ++i) {
            int remain_idx = k / factorial[n - 1 - i];
            k = k % factorial[n - 1 - i];
            ret += remain[remain_idx];
            std::move(remain.begin() + remain_idx + 1, remain.end() - i, remain.begin() + remain_idx);
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
