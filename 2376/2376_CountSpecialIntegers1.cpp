#include "../inc.h"

// 解法是对的，但是会TLE
class Solution {
   public:
    bool isSpecial(int i) {
        vector<bool> exists(10);
        while (i > 0) {
            int mod = i % 10;
            if (exists[mod]) return false;
            exists[mod] = true;
            i /= 10;
        }
        return true;
    }
    int countSpecialNumbers(int n) {
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            if (isSpecial(i)) {
                ++ret;
            }
        }
        return ret;
    }
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().countSpecialNumbers(n));
}

int main() {
    test(585362300, 4104810);
    test(20, 19);
    test(5, 5);
    test(135, 110);
    return 0;
}
