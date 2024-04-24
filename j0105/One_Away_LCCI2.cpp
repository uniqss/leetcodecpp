#include "../inc.h"

class Solution {
   public:
    bool oneEditAway(string first, string second) {
        auto& f = first;
        auto& s = second;
        if (f.size() > s.size()) swap(f, s);
        auto fsize = f.size();
        auto ssize = s.size();
        if (fsize + 1 < ssize) return false;
        size_t same = 0;
        for (size_t i = 0; i < fsize; ++i) {
            if (f[i] == s[i])
                ++same;
            else
                break;
        }
        for (int i = (int)fsize - 1; i >= 0; --i) {
            if (f[i] == s[i + ssize - fsize])
                ++same;
            else
                break;
        }
        return same + 1 >= ssize;
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
