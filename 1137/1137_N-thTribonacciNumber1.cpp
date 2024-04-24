#include "../inc.h"

/*
time complexity: O(n)
space complexity: O(n)
*/
class Solution {
   public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        vector<int> dict(n + 1);
        dict[1] = 1, dict[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dict[i] = dict[i - 1] + dict[i - 2] + dict[i - 3];
        }
        return dict[n];
    }
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().tribonacci(n));
}

int main() {
    test(4, 4);
    test(25, 1389537);
    return 0;
}
