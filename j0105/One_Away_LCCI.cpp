#include "../inc.h"

class Solution {
   public:
    bool oneEditAway(string first, string second) {}
};

void test(std::string&& first, std::string&& second, bool expect) {
    Solution so;
    auto ret = so.oneEditAway(first, second);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(first);
        print(second);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("", "", true);
    test("intention", "execution", false);
    test("pale", "ple", true);
    test("pales", "pal", false);
    return 0;
}
