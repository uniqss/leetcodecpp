#include "../inc.h"

/*
这是自己用回溯解的，没搞明白为什么不对。明明一个一个都尝试了，为什么结果不对？
修复以后累加和的时候中间节点一律左右都加。能正常跑出来，但是会超时
回溯的基本功稍显欠缺，还是得背八股文，按标准组合拳打
*/
class Solution {
    long long smin = LONG_MAX;
    long long smax = 0;

   public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k >= weights.size()) return 0;
        vector<int> splits(k - 1, 0);
        helper(weights, splits, 0, 1, k);
        return smax - smin;
    }
    void helper(vector<int>& weights, vector<int>& splits, int scount, int start, int k) {
        if (scount >= k - 1) {
            long long curr = weights[0] + weights[weights.size() - 1];
            for (int i = 0; i < scount; ++i) {
                int split = splits[i];
                curr += weights[split - 1];
                curr += weights[split];
            }

            smin = min(smin, curr);
            smax = max(smax, curr);
#if 0
            print("=======splits:");
            print(splits);
            std::cout << curr << "," << smin << "," << smax << "###########################" << endl;
#endif
            return;
        }
        // 0.1.2.3.4.5.6.7.8.9 0 3  <= 7
        //
        // int end = weights.size() - (k - scount);
        if (start >= weights.size()) return;
        // if (start > end) return;

        // select
        splits[scount] = start;
        helper(weights, splits, scount + 1, start + 1, k);

        // dont select
        helper(weights, splits, scount, start + 1, k);
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
