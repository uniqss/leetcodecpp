#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()

class Solution {
   public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.size(), qsize = queries.size(), nhalf = n / 2, l = 0;
        while (l < nhalf && s[l] == s[n - l - 1]) ++l;
        vector<bool> ret(qsize, true);
        if (l == nhalf) {
            return ret;
        }
        int r = nhalf - 1;
        while (r > l && s[r] == s[n - r - 1]) --r;
        vector<vector<int>> d1(r - l + 2, vector<int>(26)), d2(r - l + 2, vector<int>(26));
        for (int i = l; i <= r; ++i) {
            d1[i - l + 1] = d1[i - l];
            d2[i - l + 1] = d2[i - l];
            ++d1[i - l + 1][s[i] - 'a'];
            // 这里有一定的理解成本，这里把它反过来了依然用的是前缀，换算十分麻烦
            ++d2[i - l + 1][s[i - l + n - r - 1] - 'a'];
        }
        if (d1[r - l + 1] != d2[r - l + 1]) {
            ret.assign(qsize, false);
            return ret;
        }
        for (int i = 0; i < qsize; ++i) {
            const auto& q = queries[i];
            int a = q[0], b = q[1], c = q[2], d = q[3];
            int tc = n - c - 1, td = n - d - 1;
            int minl = min(a, td), minr = max(b, tc);
            if (minl > l || minr < r) {
                ret[i] = false;
            } else {
                // 不可达段中的每个元素，必须存在于交换段
                vector<int> changablel(26), changabler(26);
                a = max(a, l), b = min(b, r);
                if (a <= b) {
                    for (int j = 0; j < 26; ++j) {
                        changablel[j] += d1[b - l + 1][j] - d1[a - l + 1 - 1][j];
                    }
                }
                c = max(c, n - r - 1), d = min(d, n - l - 1);
                if (c <= d) {
                    for (int j = 0; j < 26; ++j) {
                        changabler[j] +=
                            d2[d - (n - r - 1) + 1][j] - d2[c - (n - r - 1) + 1 - 1][j];
                    }
                }
                for (int j = 0; j < 26; ++j) {
                    if (d1[r - l + 1][j] > changablel[j] + changabler[j]) {
                        ret[i] = false;
                        break;
                    }
                }
            }
        }

        return ret;
    }
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
