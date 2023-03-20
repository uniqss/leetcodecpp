#include "../inc.h"

class Solution {
   public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        std::unordered_map<char, int> dict;
        for (auto c : s1) {
            ++dict[c];
        }
        for (auto c : s2) {
            --dict[c];
        }
        for (auto it : dict) {
            if (it.second != 0) return false;
        }
        return true;
    }
};

void test(std::string s1, std::string s2, bool expect) {
    Solution so;
    auto ret = so.CheckPermutation(s1, s2);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(s1);
        print(s2);
        print(expect);
        print(ret);
    }
}

int main() {
    test("abc", "bca", true);
    test("abc", "bad", false);
    return 0;
}
