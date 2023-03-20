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
    Solution so;
    auto ret = so.isUnique(s);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok");
        print(s);
        print(expect);
        print(ret);
    }
}

int main() {
    test("leetcode", false);
    test("abc", true);
    return 0;
}
