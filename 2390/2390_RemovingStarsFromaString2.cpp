#include "../inc.h"

class Solution {
   public:
    string removeStars(string s) {
        int valid = 0, ssize = s.size();
        for (int i = 0; i < ssize; ++i) {
            if (s[i] != '*')
                s[valid++] = s[i];
            else
                --valid;
        }
        s.resize(valid);
        return s;
    }
};

void test(string s, string expect) {
    Solution so;
    auto ret = so.removeStars(s);
    assert_eq_ret(expect, ret);
    print(s);
}

int main() {
    test("leet**cod*e", "lecoe");
    test("erase*****", "");
    return 0;
}
