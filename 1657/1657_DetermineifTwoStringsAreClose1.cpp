#include "../inc.h"

class Solution {
   public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> v1(26, 0), v2(26, 0);
        for (char w : word1) ++v1[w - 'a'];
        for (char w : word2) ++v2[w - 'a'];
        for (int i = 0; i < 26; ++i)
            if ((v1[i] == 0 && v2[i] != 0) || (v1[i] != 0 && v2[i] == 0)) return false;
        sort(v1.begin(), v1.end()), sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};

void test(string word1, string word2, bool expect) {
    Solution so;
    auto ret = so.closeStrings(word1, word2);
    assert_eq_ret(expect, ret);
    print(word1);
    print(word2);
}

int main() {
    test("uau", "ssx", false);
    test("abc", "bca", true);
    test("a", "aa", false);
    test("cabbba", "abbccc", true);
    return 0;
}
