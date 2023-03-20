#include "../inc.h"

/*
这个官方写法简直太完美了
*/
class Solution {
   public:
    string compressString(string S) {
        if (S.empty()) return S;
        char ch = S[0];
        size_t count = 1;
        string ret;
        for (int i = 1; i < (int)S.size(); ++i) {
            if (S[i] == ch)
                ++count;
            else {
                ret += ch + std::to_string(count);
                ch = S[i];
                count = 1;
            }
        }
        ret += ch + std::to_string(count);
        return ret.size() < S.size() ? ret : S;
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
