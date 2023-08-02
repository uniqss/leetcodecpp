#include "../inc.h"

class Solution {
   public:
    int maxVowels(string s, int k) {
        int ret = 0, curr = 0, ssize = s.size();
        unordered_set<char> dict = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < k; ++i) {
            if (dict.count(s[i]) > 0) ++curr;
        }
        ret = curr;
        for (int i = k; i < ssize; ++i) {
            if (dict.count(s[i]) > 0) ++curr;
            if (dict.count(s[i - k]) > 0) --curr;
            ret = max(ret, curr);
        }
        return ret;
    }
};

void test(string s, int k, int expect) {
    Solution so;
    auto ret = so.maxVowels(s, k);
    assert_eq_ret(expect, ret);
    print(s);
    print(k);
}

int main() {
    test("abciiidef", 3, 3);
    test("aeiou", 2, 2);
    test("leetcode", 3, 2);

    return 0;
}
