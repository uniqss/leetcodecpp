#include "../inc.h"

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        string ret;
        int n = min(word1.size(), word2.size());
        for (int i = 0; i < n; ++i) {
            ret.push_back(word1[i]);
            ret.push_back(word2[i]);
        }
        if (word1.size() > n) ret.append(word1.substr(n));
        if (word2.size() > n) ret.append(word2.substr(n));

        return ret;
    }
};

void test(string&& word1, string&& word2, const string& expect) {
    Solution so;
    auto ret = so.mergeAlternately(word1, word2);
    assert_eq_ret(expect, ret);
    print(word1);
    print(word2);
}

int main() {
    test("abc", "pqr", "apbqcr");
    test("ab", "pqrs", "apbqrs");
    test("abcd", "pq", "apbqcd");
    return 0;
}
