#include "../inc.h"

class Solution {
   public:
    bool oneEditAway(string first, string second) {}
};

void test(std::string&& first, std::string&& second, bool expect) {
    save4print(first, second);
    assert_eq_ret(expect, Solution().oneEditAway(first, second));
}

int main() {
    test("", "", true);
    test("intention", "execution", false);
    test("pale", "ple", true);
    test("pales", "pal", false);
    return 0;
}
