#include "../inc.h"

class Solution {
   public:
    string reverseStr(string s, int k) {
        int ssize = s.size();
        int loop = ssize / (k * 2);
        if (k <= 1) return s;
        for (int i = 0; i < loop; ++i) {
            reverse(s.begin() + i * 2 * k, s.begin() + (i * 2 * k) + k);
        }
        if (loop * k * 2 < ssize) reverse(s.begin() + loop * k * 2, s.begin() + min(ssize, loop * k * 2 + k));

        return s;
    }
};

void test(string&& s, int k, const string& expect) {
    Solution so;
    auto ret = so.reverseStr(s, k);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(s);
        print(k);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("abcdefg", 8, "gfedcba");
    test("abcdefg", 2, "bacdfeg");
    test("abcd", 2, "bacd");
    return 0;
}
