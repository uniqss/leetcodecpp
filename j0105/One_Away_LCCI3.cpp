#include "../inc.h"

// 越写越好看

class Solution {
   public:
    bool oneEditAway(string first, string second) {
        size_t same = 0, s1 = first.size(), s2 = second.size();
        for (size_t i = 0; i < s1 && i < s2; ++i) {
            if (first[i] == second[i])
                ++same;
            else
                break;
        }
        for (int i = 0; i < s1 && i < s2; ++i) {
            if (first[s1 - i - 1] == second[s2 - i - 1])
                ++same;
            else
                break;
        }
        return same + 1 >= max(s1, s2);
    }
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
