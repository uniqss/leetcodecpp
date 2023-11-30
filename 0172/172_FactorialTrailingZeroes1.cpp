#include "../inc.h"

// 本来挺简单，数一下，1个5就是1个0，因为2很充足，一定有2匹配。
// 在30的时候会翻车，准确的说，是在25的时候会翻车，不光统计5的个数，因为25它是2个5乘在一起，会多出来1个5。
// 如果到625，会又多出来1个5
class Solution {
   public:
    int trailingZeroes(int n) {
        int ret = 0;
        while (n > 0) {
            ret += n / 5;
            n /= 5;
        }
        return ret;
    }
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().trailingZeroes(n));
}

int main() {
    test(30, 7);
    test(3, 0);
    test(5, 1);
    test(0, 0);
    return 0;
}
