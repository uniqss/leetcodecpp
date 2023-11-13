#include "../inc.h"

class Solution {
   public:
    string addBinary(string a, string b) {
        int curr = 0;
        string ret;
        int asize = a.size();
        int bsize = b.size();
        int msize = max(asize, bsize);
        for (int i = 0; i < msize; i++) {
            if (i < asize) curr += a[asize - 1 - i] - '0';
            if (i < bsize) curr += b[bsize - 1 - i] - '0';
            ret.push_back(curr % 2 == 0 ? '0' : '1');
            curr /= 2;
        }
        if (curr > 0) ret.push_back('1');
        std::reverse(ret.begin(), ret.end());
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
