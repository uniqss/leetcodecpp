#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()


class Solution {
   public:
    int maximumLength(string s) {}
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
