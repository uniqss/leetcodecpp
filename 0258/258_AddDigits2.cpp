#include "../inc.h"

/*
这是一个逆天的写法，属于数学家的降维打击，会对数学不好的人造成成吨的暴击伤害和巨大的心理阴影，求阴影部分的面积

已知： y(x * 10 + a) = y(x + a)
求证： y(x) = 1 + (x - 1) % 9
不对，应该说，y(x) = 1 + (x - 1) % 9 是其中的一个解，而且是个比较简约的解。实数范围内一定有其他解，所以没有求证一说。
只能反证说 { y(x) = 1 + (x - 1) % 9 不满足 y(x * 10 + a) = y(x + a) } 不成立，从而证明它是其中的一个解。

*/
class Solution {
   public:
    int addDigits(int num) { return 1 + (num - 1) % 9; }
};

void test(int num, int expect) {
    Solution so;
    auto ret = so.addDigits(num);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(num);
        print(expect);
        print(ret);
    }
}

int main() {
    test(38, 2);
    test(0, 0);
    test(10, 1);
    return 0;
}
