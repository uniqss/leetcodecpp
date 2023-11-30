#include "../inc.h"

class Solution {
   public:
    int compress(vector<char>& chars) {
        int ret = 0;
        char last = chars[0];
        int csize = chars.size(), count = 1;
        int countbits = 0;
        for (size_t i = 1; i < csize; ++i) {
            if (chars[i] == last) {
                ++count;
            } else {
                chars[ret] = last;
                ++ret;
                if (count != 1) {
                    countbits = 0;
                    while (count > 0) {
                        chars[ret] = '0' + count % 10;
                        ++ret;
                        count /= 10;
                        ++countbits;
                    }
                    reverse(chars.begin() + ret - countbits, chars.begin() + ret);
                }
                count = 1;
                last = chars[i];
            }
        }
        chars[ret] = last;
        ++ret;
        if (count != 1) {
            countbits = 0;
            while (count > 0) {
                chars[ret] = '0' + count % 10;
                ++ret;
                count /= 10;
                ++countbits;
            }
            reverse(chars.begin() + ret - countbits, chars.begin() + ret);
        }
        chars.resize(ret);

        return ret;
    }
};

void test(vector<char>&& chars, int expect) {
    save4print(chars);
    assert_eq_ret(expect, Solution().compress(chars));
}

int main() {
    test({'a', 'a', 'b', 'b', 'c', 'c', 'c'}, 6);
    test({'a'}, 1);
    test({'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}, 4);
    return 0;
}
