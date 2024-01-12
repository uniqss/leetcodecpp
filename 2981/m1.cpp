#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()


class Solution {
   public:
    int maximumLength(string s) {
        int ret = 0, ssize = s.size();
        unordered_map<string, int> dict;
        for (int l = 1; l <= ssize - 2; ++l) {
            for (int j = 0; j < ssize - l + 1; ++j) {
                bool same = true;
                for (int k = j + 1; k < j + l; ++k)
                    if (s[k] != s[j]) {
                        same = false;
                        break;
                    }
                if (!same) continue;
                string curr = s.substr(j, l);
                if (++dict[curr] >= 3) ret = max(ret, l);
            }
        }
        return ret == 0 ? -1 : ret;
    }
};


void test(string s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().maximumLength(s));
}

int main() {
    test("cccerrrecdcdccedecdcccddeeeddcdcddedccdceeedccecde", 2);
    test("aaaa", 2);
    test("abcdef", -1);
    test("abcaba", 1);
    return 0;
}
