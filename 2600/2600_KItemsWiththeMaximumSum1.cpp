#include "../inc.h"

class Solution {
   public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k <= numOnes) {
            return k;
        } else if (k <= numOnes + numZeros) {
            return numOnes;
        } else {
            return numOnes - (k - numOnes - numZeros);
        }
    }
};


void test(int numOnes, int numZeros, int numNegOnes, int k, int expect) {
    Solution so;
    auto ret = so.kItemsWithMaximumSum(numOnes, numZeros, numNegOnes, k);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(numOnes);
        print(numZeros);
        print(numNegOnes);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test(3, 2, 0, 2, 2);
    test(3, 2, 0, 4, 3);
    return 0;
}
