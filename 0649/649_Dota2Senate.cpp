#include "../inc.h"

class Solution {
   public:
    string predictPartyVictory(string senate) {}
};

void test(string senate, const string& expect) {
    save4print(senate);
    assert_eq_ret(expect, Solution().predictPartyVictory(senate));
}

int main() {
    test("DDRRR", "Dire");
    test("RD", "Radiant");
    test("DR", "Dire");
    test("RDD", "Dire");

    return 0;
}
