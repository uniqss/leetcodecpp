#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()

class Solution {
   public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {}
};

void test(string s, vector<vector<int>>&& queries, const vector<bool>& expect) {
    save4print(s, queries);
    assert_eq_ret(expect, Solution().canMakePalindromeQueries(s, queries));
}

int main() {
    test("ckwbnmqmtzbixrrkixbtbqzmnwmc", {{1, 9, 15, 24}}, {true});
    test("deceecde", {{3, 3, 6, 7}, {1, 2, 4, 5}, {2, 3, 7, 7}}, {true, false, false});
    test("odaxusaweuasuoeudxwa", {{0, 5, 10, 14}}, {false});
    test("abcabc", {{1, 1, 3, 5}, {0, 2, 5, 5}}, {true, true});
    test("abbcdecbba", {{0, 2, 7, 9}}, {false});
    test("acbcab", {{1, 2, 4, 5}}, {true});
    return 0;
}
