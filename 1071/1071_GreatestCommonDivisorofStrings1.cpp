#include "../inc.h"

class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {
        string ret;
        int n1 = str1.size(), n2 = str2.size();
        int gcd = 1, gcdmax = std::min(n1, n2);
        // 思路：先计算 n1/n2 的 gcd 的int值，再拿这个值去挨个比，一定是这个值里面的一个
        unordered_set<int> gcds = {1};
        int gcdsmax = 1;
        for (int i = 2; i <= gcdmax; ++i) {
            if (n1 % i == 0 && n2 % i == 0) {
                gcds.insert(i);
                gcdsmax = max(gcdsmax, i);
            }
        }
        int maxsame = 0;
        for (int i = 0; i < gcdsmax; ++i) {
            if (str1[i] != str2[i]) break;
            ++maxsame;
        }
        for (int currgcd = maxsame; currgcd >= 1; --currgcd) {
            if (gcds.count(currgcd) == 0) continue;
            bool same = true;
            for (int i = 1; i < n1 / currgcd; ++i) {
                for (int idx = 0; idx < currgcd; ++idx) {
                    if (str1[i * currgcd + idx] != str1[idx]) {
                        same = false;
                        break;
                    }
                }
                if (!same) break;
            }
            if (!same) continue;

            for (int i = 1; i < n2 / currgcd; ++i) {
                for (int idx = 0; idx < currgcd; ++idx) {
                    if (str2[i * currgcd + idx] != str1[idx]) {
                        same = false;
                        break;
                    }
                }
                if (!same) break;
            }
            if (same) return str1.substr(0, currgcd);
        }

        return ret;
    }
};

void test(string&& str1, string&& str2, const string& expect) {
    Solution so;
    auto ret = so.gcdOfStrings(str1, str2);
    assert_eq_ret(expect, ret);
    print(str1);
    print(str2);
}

int main() {
    test("ABCABC", "ABC", "ABC");
    test("ABABAB", "ABAB", "AB");
    test("LEET", "CODE", "");
    return 0;
}
