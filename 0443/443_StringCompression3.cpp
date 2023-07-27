#include "../inc.h"

class Solution {
   public:
    int compress(vector<char>& chars) {
        int csize = chars.size(), ret = 0, count = 1, countlen = 0;
        if (csize == 1) return 1;
        char last = chars[0];
        for (int i = 1; i <= csize; ++i) {
            if (i == csize || chars[i] != last) {
                chars[ret++] = last;
                if (count > 1) {
                    countlen = 0;
                    while (count > 0) {
                        chars[ret++] = '0' + count % 10;
                        count /= 10;
                        ++countlen;
                    }
                    if (countlen > 1) reverse(chars.begin() + ret - countlen, chars.begin() + ret);
                }
                if (i < csize) last = chars[i];
                count = 1;
            } else {
                ++count;
            }
        }

        return ret;
    }
};

void test(vector<char>&& chars, int expect) {
    auto chars_param = chars;
    Solution so;
    auto ret = so.compress(chars);
    assert_eq_ret(expect, ret);
    print(chars_param);
}

int main() {
    test({'a', 'a', 'b', 'b', 'c', 'c', 'c'}, 6);
    test({'a'}, 1);
    test({'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}, 4);
    return 0;
}
