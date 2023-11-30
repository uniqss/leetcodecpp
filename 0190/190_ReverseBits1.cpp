#include "../inc.h"

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & 0x01) != 0) ret |= 0x01;
            if (i < 31) ret <<= 1;
            n >>= 1;
        }
        return ret;
    }
};

void test(uint32_t n, uint32_t expect) {
    save4print((int)n);
    assert_eq_ret(expect, Solution().reverseBits(n));
}

int main() {
    test(0b00000010100101000001111010011100, 964176192);
    test(0b11111111111111111111111111111101, 0b10111111111111111111111111111111);
    return 0;
}
