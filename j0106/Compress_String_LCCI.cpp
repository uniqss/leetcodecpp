#include "../inc.h"

class Solution {
   public:
    string compressString(string S) {}
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
