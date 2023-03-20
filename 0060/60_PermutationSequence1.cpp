#include "../inc/inc.h"

class Solution {
   public:
    string getPermutation(int n, int k) {
        string val(n, '1');
        for (int i = 0; i < n; ++i) {
            val[i] += i;
        }
        while (--k > 0) {
            int pos = -1;
            for (int i = n - 1; i > 0; --i) {
                if (val[i] > val[i - 1]) {
                    pos = i - 1;
                    break;
                }
            }
            int right_pos = -1;
            char right_val = CHAR_MAX;
            for (int i = n - 1; i > pos; --i) {
                if (val[i] > val[pos] && val[i] < right_val) {
                    right_val = val[i];
                    right_pos = i;
                }
            }
            swap(val[pos], val[right_pos]);
            if (pos < n - 2) sort(val.begin() + pos + 1, val.end());
        }
        return val;
    }
};

void test(int n, int k, const string& expect) {
    Solution so;
    auto ret = so.getPermutation(n, k);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(n);
        print(k);
        print(expect);
        print(ret);
    }
}

int main() {
    test(3, 3, "213");
    test(4, 9, "2314");
    test(3, 1, "123");
    return 0;
}
