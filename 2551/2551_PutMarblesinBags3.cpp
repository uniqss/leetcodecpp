#include "../inc.h"

/*
从这里算的结果，再反推之前回溯的问题，每个分隔点无论以0-indexed还是1-indexed，分隔点左右都必加，另外加头尾
*/

class Solution {
   public:
    long long putMarbles(const vector<int>& wt, int k) {
        int nsize = wt.size();
        vector<pair<int, int>> dict(nsize - 1);
        for (int i = 0; i < nsize - 1; ++i) {
            dict[i] = {wt[i] + wt[i + 1], i};
        }
        sort(dict.begin(), dict.end(),
             [](const pair<int, int>& lhs, const pair<int, int>& rhs) { return lhs.first < rhs.first; });

        long long ret = 0;
        for (int i = 0; i < k - 1; ++i) {
            ret += dict[nsize - 2 - i].first - dict[i].first;
        }

#if 1
        vector<int> idxmax;
        cout << "max:[";
        for (int i = 0; i < k - 1; ++i) {
            idxmax.push_back(dict[nsize - 2 - i].second);
            cout << dict[nsize - 2 - i].second << ", ";
        }
        sort(idxmax.begin(), idxmax.end());
        long long valmax = wt[0] + wt[nsize - 1];
        for (int split : idxmax) {
            valmax += wt[split];
            valmax += wt[split + 1];
        }
        cout << "] valmax:" << valmax << endl;

        vector<int> idxmin;
        cout << "min:[";
        for (int i = 0; i < k - 1; ++i) {
            idxmin.push_back(dict[i].second);
            cout << dict[i].second << ", ";
        }
        sort(idxmin.begin(), idxmin.end());
        long long valmin = wt[0] + wt[nsize - 1];
        for (int split : idxmin) {
            valmin += wt[split];
            valmin += wt[split + 1];
        }
        cout << "] valmin:" << valmin << endl;

#endif

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
