#include "../inc.h"

class Solution {
   public:
    bool isUnique(string astr) {
        std::unordered_set<char> dict;
        for (const auto c : astr) {
            if (dict.count(c) > 0) return false;
            dict.insert(c);
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
