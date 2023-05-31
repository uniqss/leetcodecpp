#include "../inc.h"

class Solution {
   public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
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
