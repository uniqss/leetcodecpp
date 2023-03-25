#include "../inc.h"

class Solution {
   public:
    bool canPermutePalindrome(string s) {
        if (s.size() < 2) return true;
        int oddCount = 0;
        unordered_map<char, bool> dict;
        for (auto c : s) {
            if (dict[c]) {
                dict[c] = false;
                --oddCount;
            } else {
                dict[c] = true;
                ++oddCount;
            }
        }
        return oddCount <= 1;
    }
};

void test(std::string&& s, bool expect) {
    Solution so;
    auto ret = so.canPermutePalindrome(s);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(s);
        print(expect);
        print(ret);
    }
}

int main() {
    test("code", false);
    test("aab", true);
    test("tactcoa", true);
    return 0;
}
