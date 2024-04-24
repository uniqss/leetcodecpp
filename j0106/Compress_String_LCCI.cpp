#include "../inc.h"

class Solution {
   public:
    string compressString(string S) {}
};

void test(std::string&& s, const std::string& expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().compressString(s));
}

int main() {
    test("aaaaaaaaaa", "a10");
    test(
        "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNfffff"
        "f",
        "r5L5P6R5g3N5V10D10I10l7A4q7b3N4f6");
    test("ccc", "c3");
    test("aabcccccaaa", "a2b1c5a3");
    test("abbccd", "abbccd");

    return 0;
}
