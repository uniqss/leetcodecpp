#include "../inc.h"

/*
时间复杂度：O(log(num)^2)
空间复杂度：O(log(num))
*/
class Solution {
   public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 9) continue;
            int j = n - 1, jmax = -1;
            while (j > i) {
                if (s[j] > s[i]) {
                    if (jmax == -1 || s[jmax] < s[j]) jmax = j;
                }
                --j;
            }
            if (jmax != -1) {
                swap(s[i], s[jmax]);
                break;
            }
        }
        return atoi(s.c_str());
    }
};

void test(int num, int expect) {
    save4print(num);
    assert_eq_ret(expect, Solution().maximumSwap(num));
}
int main() {
    test(2736, 7236);
    test(9973, 9973);
    test(98368, 98863);
    return 0;
}