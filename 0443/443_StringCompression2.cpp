#include "../inc.h"

class Solution {
   public:
    int compress(vector<char>& chars) {
        char last = chars[0];
        int count = 1, csize = chars.size(), pos = 0;
        for (int i = 1; i < csize; ++i) {
            if (chars[i] == last)
                ++count;
            else {
                chars[pos++] = last;
                if (count > 1) {
                    int countlen = 0;
                    while (count > 0) {
                        ++countlen;
                        chars[pos++] = '0' + count % 10;
                        count /= 10;
                    }
                    reverse(chars.begin() + pos - countlen, chars.begin() + pos);
                }
                count = 1;
                last = chars[i];
            }
        }
        chars[pos++] = last;
        if (count > 1) {
            int countlen = 0;
            while (count > 0) {
                ++countlen;
                chars[pos++] = '0' + count % 10;
                count /= 10;
            }
            reverse(chars.begin() + pos - countlen, chars.begin() + pos);
        }
        chars.resize(pos);

        return pos;
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
