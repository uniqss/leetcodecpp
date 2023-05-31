#include "../inc.h"

/*
做了半天发现审题失误，，，必须保持有序不能重排，那就不是一棵完全二叉树，还证明顺序个球。。。
*/
class Solution {
   public:
    int mctFromLeafValues(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ret = 0;
        int asize = arr.size();
        /*
        step = 2 a[0] * a[1]  a[2] * a[3]  a[4] * a[5]  a[6] * a[7]
        step = 4 a[1] * a[3]  a[5] * a[7]
        step = 8 a[3] * a[7]
        */
        int lstart = 0, rstart = 1, step = 2;
        while (lstart + 1 < asize) {
            int l = lstart, r = rstart;
            while (l + 1 < asize) {
                if (r < asize)
                    ret += arr[l] * arr[r];
                else
                    ret += arr[l] * arr[asize - 1];
                l += step;
                r += step;
            }
            lstart += step / 2;
            rstart += step;
            step *= 2;
        }

        return ret;
    }
};

void test(vector<int>&& arr, int expect) {
    Solution so;
    auto arr_param = arr;
    auto ret = so.mctFromLeafValues(arr);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(arr_param);
        print(expect);
        print(ret);
    }
}

int main() {
    test({7, 12, 8, 10}, 284);
    test({6, 2, 4}, 32);
    test({4, 11}, 44);
    return 0;
}
