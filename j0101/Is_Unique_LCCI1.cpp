#include "../inc.h"

class Solution {
   public:
    bool isUnique(string astr) {
        const auto size = astr.size();
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = i + 1; j < size; ++j) {
                if (astr[i] == astr[j]) return false;
            }
        }
        return true;
    }
};

void test(const std::string& s, bool expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().isUnique(s));
}

int main() {
    test("leetcode", false);
    test("abc", true);
    return 0;
}
