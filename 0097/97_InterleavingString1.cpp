#include "../inc.h"

// 理论上是对的，但是会超时
class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.empty()) return s2 == s3;
        if (s2.empty()) return s1 == s3;
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        return helper(s1, s2, s3, 0, 0, 0);
    }
    bool helper(const string& s1, const string& s2, const string& s3, int i, int j, int k) {
        if (k == s3.size()) return true;
        if (i == s1.size()) {
            if (s2[j] == s3[k]) {
                return helper(s1, s2, s3, i, j + 1, k + 1);
            } else {
                return false;
            }
        } else if (j == s2.size()) {
            if (s1[i] == s3[k]) {
                return helper(s1, s2, s3, i + 1, j, k + 1);
            } else {
                return false;
            }
        } else {
            if (s1[i] == s3[k]) {
                if (helper(s1, s2, s3, i + 1, j, k + 1)) return true;
            }
            if (s2[j] == s3[k]) {
                if (helper(s1, s2, s3, i, j + 1, k + 1)) return true;
            }
        }
        return false;
    }
};

void test(string s1, string s2, string s3, bool expect) {
    save4print(s1, s2, s3);
    assert_eq_ret(expect, Solution().isInterleave(s1, s2, s3));
}

int main() {
    test("aabcc", "dbbca", "aadbbcbcac", true);
    test("aabcc", "dbbca", "aadbbbaccc", false);
    test("", "", "", true);
    return 0;
}
