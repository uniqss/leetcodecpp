#include "../inc.h"

// even a number can be happy, why not you?
class Solution {
    unordered_set<int> dict;

   public:
    bool isHappy(int n) {
        dict.insert(n);
        int sum = n, mod = 0;
        while (true) {
            n = sum;
            sum = 0;
            while (n > 0) {
                mod = n % 10;
                sum += mod * mod;
                n /= 10;
            }
            if (sum == 1) return true;
            if (dict.count(sum) > 0) return false;
            dict.insert(sum);
        }
        return false;
    }
};

void test(int n, bool expect) {
    save4print(n);
    Solution so;
    auto ret = so.isHappy(n);
    assert_eq_ret(expect, ret);
}

int main() {
    test(1, true);
    test(19, true);
    test(2, false);
    return 0;
}
