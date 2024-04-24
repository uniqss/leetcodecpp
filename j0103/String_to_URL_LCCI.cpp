#include "../inc.h"


class Solution {
   public:
    string replaceSpaces(string S, int length) {}
};

void test(std::string s, int length, const std::string& expect) {
    save4print(s, length);
    assert_eq_ret(expect, Solution().replaceSpaces(s, length));
}

int main() {
    test("ds sdfs afs sdfa dfssf asdf             ", 27, "ds%20sdfs%20afs%20sdfa%20dfssf%20asdf");
    test("Mr John Smith    ", 13, "Mr%20John%20Smith");
    test("               ", 5, "%20%20%20%20%20");
    return 0;
}
