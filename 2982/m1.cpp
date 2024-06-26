#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()


class Solution {
   public:
    int maximumLength(string s) {
        s.push_back('#');
        int n = s.size(), len = 1, ret = -1;
        char last = s[0];
        // unordered_map<s[i], map<len, count>>
        unordered_map<char, map<int, int>> dict;
        for (int i = 1; i < n; ++i) {
            if (s[i] == last)
                ++len;
            else {
                auto& m = dict[last];
                if (len >= 3) {
                    m[len - 1] += 2;
                    m[len - 2] += 3;
                    if (m[len - 1] >= 3) ret = max(ret, len - 1);
                    if (m[len - 2] >= 3) ret = max(ret, len - 2);
                } else if (len == 2) {
                    m[len - 1] += 2;
                    if (m[len - 1] >= 3) ret = max(ret, len - 1);
                }
                ++m[len];
                if (m[len] >= 3) ret = max(ret, len);

                len = 1;
                last = s[i];
            }
        }
        return ret;
    }
};


void test(string s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().maximumLength(s));
}

int main() {
    test("eccdnmcnkl", 1);
    test("cccerrrecdcdccedecdcccddeeeddcdcddedccdceeedccecde", 2);
    test("aaaa", 2);
    test("abcdef", -1);
    test("abcaba", 1);
    return 0;
}
