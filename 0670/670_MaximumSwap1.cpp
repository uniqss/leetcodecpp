#include "../inc.h"

class Solution {
   public:
    int maximumSwap(int num) {
        int t = num;
        vector<int> d;
        while (t > 0) {
            d.push_back(t % 10);
            t /= 10;
        }
        reverse(d.begin(), d.end());
        int n = d.size();
        for (int i = 0; i < n; ++i) {
            if (d[i] == 9) continue;
            int j = n - 1, jmax = -1;
            while (j > i) {
                if (d[j] > d[i]) {
                    if (jmax == -1 || d[jmax] < d[j]) jmax = j;
                }
                --j;
            }
            if (jmax != -1) {
                t = 0;
                swap(d[i], d[jmax]);
                for (int k = 0; k < n; ++k) {
                    t = t * 10 + d[k];
                }
                return t;
            }
        }
        return num;
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