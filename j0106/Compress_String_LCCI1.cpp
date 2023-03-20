#include "../inc.h"

/*
我想我的写法是和原作者的思路更近的。反正都是o(n)，不如先搞一次，再搞一次，省掉字符串的一堆操作，性能会高很多
*/
class Solution {
   public:
    string compressString(string S) {
        if (S.size() <= 2) return S;
        std::size_t ssize = S.size(), csize = 0, count = 0;
        for (size_t i = 0; i <= ssize; ++i) {
            if (i == 0 || i > 0 && i < ssize && S[i] == S[i - 1]) {
                ++count;
                continue;
            } else {
                if (count < 10)
                    csize += 2;
                else if (count < 100)
                    csize += 3;
                else if (count < 1000)
                    csize += 4;
                else if (csize < 10000)
                    csize += 5;
                else
                    csize += 6;
                count = 1;
            }
        }
        if (csize >= ssize) return S;
        std::string ret;
        ret.reserve(csize);
        count = 0;
        for (size_t i = 0; i <= ssize; ++i) {
            if (i == 0 || i > 0 && i < ssize && S[i] == S[i - 1]) {
                ++count;
                continue;
            } else {
                ret.push_back(S[i - 1]);
                size_t start = ret.size(), len = 0;
                while (count > 0) {
                    char mod = count % 10;
                    count /= 10;
                    ret.push_back('0' + mod);
                    ++len;
                }
                std::reverse(ret.begin() + start, ret.begin() + start + len);
                count = 1;
            }
        }
        return ret;
    }
};

void test(std::string&& s, const std::string& expect) {
    Solution so;
    auto ret = so.compressString(s);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(s);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("aaaaaaaaaa", "a10");
    test("rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff",
         "r5L5P6R5g3N5V10D10I10l7A4q7b3N4f6");
    test("ccc", "c3");
    test("aabcccccaaa", "a2b1c5a3");
    test("abbccd", "abbccd");

    return 0;
}
