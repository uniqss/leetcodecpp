#include "../inc.h"

/*
这个思路是可以的
我看到了头尾可略
我看到了逗号左右

我思考不足的点：
    没有想到用排序去做，想办法把数据转化成可以用排序的方式
    没有看透事情的本质，［选择一个点，并不会影响下一个点的选择］

    那么我们来想办法，把最终结果要先的idx给它打印出来，找出到底怎么排列是最大，怎么排列是最小----3里面实现
*/

class Solution {
   public:
    long long putMarbles(vector<int>& wt, int k) {
        int nsize = wt.size();
        for (int i = 0; i < nsize - 1; ++i) {
            wt[i] += wt[i + 1];
        }
        sort(wt.begin(), wt.end() - 1);
        long long ret = 0;
        for (int i = 0; i < k - 1; ++i) {
            ret += wt[nsize - 2 - i] - wt[i];
        }
        return ret;
    }
};


void test(vector<int>&& weights, int k, long long expect) {
    auto weights_param = weights;
    Solution so;
    auto ret = so.putMarbles(weights, k);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(weights_param);
        print(k);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({54, 6, 34, 66, 63, 52, 39, 62, 46, 75, 28, 65, 18, 37, 18, 13, 33, 69, 19, 40, 13, 10, 43, 61, 72}, 4, 289);
    test({1, 4, 2, 5, 2}, 3, 3);
    test({1, 3, 5, 1}, 2, 4);
    test({1, 3}, 2, 0);

    return 0;
}
