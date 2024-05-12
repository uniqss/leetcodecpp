#include "../inc.h"

class Solution {
   public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0, v1, v2;
        while (i < n1 || j < n2) {
            v1 = 0, v2 = 0;
            while (i < n1 && version1[i] != '.') {
                v1 = v1 * 10 + version1[i] - '0';
                ++i;
            }
            while (j < n2 && version2[j] != '.') {
                v2 = v2 * 10 + version2[j] - '0';
                ++j;
            }
            if (v1 != v2) return v1 > v2 ? 1 : -1;
            ++i, ++j;
        }
        return 0;
    }
};

void test(string&& version1, string&& version2, int expect) {
    save4print(version1, version2);
    assert_eq_ret(expect, Solution().compareVersion(version1, version2));
}

int main() {
    test("1.01", "1.001", 0);
    test("1.0", "1.0.0", 0);
    test("0.1", "1.1", -1);
    return 0;
}
