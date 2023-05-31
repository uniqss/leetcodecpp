#include "../inc.h"

class Solution {
   public:
    int mctFromLeafValues(vector<int>& arr) {}
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
    test({12, 4, 13, 8,  10, 1,  5, 14, 5,  4, 3, 11, 6, 7,  5,  12, 6, 4, 14, 15,
          2,  2, 11, 13, 10, 15, 3, 11, 15, 1, 2, 10, 6, 14, 15, 9,  7, 9, 9,  5},
         3898);
    test({6, 2, 4}, 32);
    test({4, 11}, 44);
    test({7, 12, 8, 10}, 284);
    return 0;
}
