#include "../inc.h"

class Solution {
   public:
    string convert(string s, int numRows) {
        /*
        0
        1 5
        2 4
        3
        numRows = 4, n = 6
        i = 4, mod = 4
        */
        if (numRows == 1) return s;
        string ret;
        int n = 2 * numRows - 2, ssize = s.size(), section = ssize / n;
        vector<string> dict(numRows);
        for (int i = 0; i < ssize; ++i) {
            int mod = i % n;
            if (mod < numRows)
                dict[mod] += s[i];
            else
                dict[n - mod] += s[i];
        }
        for (const auto& d : dict) ret += d;
        return ret;
    }
};

void test(string s, int numRows, string expect) {
    save4print(s);
    save4print(numRows);
    Solution so;
    auto ret = so.convert(s, numRows);
    assert_eq_ret(expect, ret);
}

int main() {
    test("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    test("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
    test("A", 1, "A");
    return 0;
}
