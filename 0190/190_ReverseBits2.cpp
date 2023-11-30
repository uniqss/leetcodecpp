#include "../inc.h"

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 16; ++i) {
            int r = n & (1 << i);
            int l = n & (1 << (32 - i - 1));
            if (l) ret |= (1 << i);
            if (r) ret |= (1 << (32 - i - 1));
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
