#include "../inc.h"

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
        事实上，还有进一步优化空间：
            前面的负数其实我们可以无视之。
            因为总和>=0一定有解(这是个数学问题，可以自己推理一下，很容易) 所以前面的负不影响，并且也不需要加到尾巴上。
            不用加在尾巴上的原因：返回值一定是某个连续或单个的正数的第一个下标。前面的负数被忽略了，两种可能
                前面无负数，无视，就跟正常处理一样
                    尾巴为正
                    尾巴为负
                前面有负数
                    尾巴为正，不可能丢失 -4, ..., -1, 2, 3 比如这样，这个起始的正数2一定会被抓到，只要total能保证，一定能保证
                    尾巴为负，无视，因为返回一定为正
        */
        int n = gas.size(), remain, total = 0, sum = 0, ret = -1;
        for (int i = 0; i < n; ++i) {
            remain = gas[i] - cost[i];
            total += remain;
            if (sum + remain >= 0) {
                if (ret == -1) ret = i;
                sum += remain;
            } else {
                sum = 0;
                ret = -1;
            }
        }
        return total >= 0 ? ret : -1;
    }
};

void test(vector<int>&& gas, vector<int>&& cost, int expect) {
    save4print(gas, cost);
    assert_eq_ret(expect, Solution().canCompleteCircuit(gas, cost));
}

int main() {
    test({1, 1, 3}, {2, 2, 1}, 2);
    test({4}, {5}, -1);
    // {-2, -2, -2, 3, 3}
    test({4, 5, 3, 1, 4}, {5, 4, 3, 4, 2}, -1);
    test({3, 3, 4}, {3, 4, 4}, -1);
    test({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 3);
    test({2, 3, 4}, {3, 4, 3}, -1);
    return 0;
}