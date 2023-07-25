#include "../inc.h"

class Solution {
   public:
    int compress(vector<char>& chars) {
        int csize = chars.size(), count = 1, valid = 0, numstart = 0;
        char last = chars[0];
        for (int i = 1; i < csize; ++i) {
            if (chars[i] == last)
                ++count;
            else {
                chars[valid++] = last;
                if (count > 1) {
                    numstart = valid;
                    while (count > 0) {
                        chars[valid++] = '0' + count % 10;
                        count /= 10;
                    }
                    reverse(chars.begin() + numstart, chars.begin() + valid);
                }

                last = chars[i];
                count = 1;
            }
        }
        chars[valid++] = last;
        if (count > 1) {
            numstart = valid;
            while (count > 0) {
                chars[valid++] = '0' + count % 10;
                count /= 10;
            }
            reverse(chars.begin() + numstart, chars.begin() + valid);
        }

        return valid;
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
