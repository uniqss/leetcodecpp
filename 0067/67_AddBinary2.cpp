#include "../inc.h"

class Solution {
   public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, sum = 0;
        string ret;
        while (i >= 0 || j >= 0 || sum > 0) {
            if (i >= 0) sum += a[i] - '0', --i;
            if (j >= 0) sum += b[j] - '0', --j;
            ret.push_back('0' + sum % 2);
            sum /= 2;
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

void test(string a, string b, string expect) {
    save4print(a, b);
    assert_eq_ret(expect, Solution().addBinary(a, b));
}

int main() {
    test("11", "1", "100");
    test("1010", "1011", "10101");
    return 0;
}
