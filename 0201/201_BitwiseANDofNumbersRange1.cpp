#include "../inc.h"

class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        bool same = true;
        int ret = 0;
        // 这个30需要理解一下，以2^8=256为例，最高位是128，但最高位标示正负，所以只能到左数第2个位也就是2^6=2^(8 - 2)
        int mod = 1 << 30;
        while (mod != 0 && same) {
            if ((left & mod) != (right & mod))
                same = false;
            else
                ret |= (left & mod);
            mod >>= 1;
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
