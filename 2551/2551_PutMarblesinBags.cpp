#include "../inc.h"

class Solution {
   public:
    long long putMarbles(vector<int>& wt, int k) {}
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
