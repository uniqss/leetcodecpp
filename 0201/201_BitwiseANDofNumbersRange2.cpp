#include "../inc.h"

class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        int ret = 0;
        for (int i = 30; i >= 0; --i) {
            if ((left & (1 << i)) != (right & (1 << i))) break;
            ret |= (left &(1 << i));
        }
        return ret;
    }
};

void test(int left, int right, int expect) {
    save4print(left, right);
    assert_eq_ret(expect, Solution().rangeBitwiseAnd(left, right));
}

int main() {
    test(5, 7, 4);
    test(0, 0, 0);
    test(1, 2147483647, 0);
    return 0;
}
