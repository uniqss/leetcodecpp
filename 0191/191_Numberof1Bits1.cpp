#include "../inc.h"

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n != 0) {
            if ((n & 0x01) == 1) ++ret;
            n >>= 1;
        }

        return ret;
    }
};

void test(uint32_t n, int expect) {
    save4print((int)n);
    assert_eq_ret(expect, Solution().hammingWeight(n));
}

int main() {
    test(0b00000000000000000000000000001011, 3);
    test(0b00000000000000000000000010000000, 1);
    test(0b11111111111111111111111111111101, 31);
    return 0;
}
