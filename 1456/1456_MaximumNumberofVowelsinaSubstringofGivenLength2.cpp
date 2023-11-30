#include "../inc.h"

class Solution {
   public:
    int maxVowels(string s, int k) {
        int ssize = s.size(), qsize = 0, acurr = 0, amax = 0;
        queue<int> q;
        unordered_set<char> dict = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < ssize; ++i) {
            if (dict.count(s[i]) > 0) {
                if (q.empty() || q.back() < 0) {
                    q.push(1);
                } else {
                    ++q.back();
                }
                ++acurr;
            } else {
                if (q.empty() || q.back() > 0) {
                    q.push(-1);
                } else {
                    --q.back();
                }
            }
            if (++qsize > k) {
                if (q.front() > 0) {
                    --q.front();
                    --acurr;
                } else {
                    ++q.front();
                }
                if (q.front() == 0) q.pop();
            }
            amax = max(amax, acurr);
        }
        return amax;
    }
};

void test(string s, int k, int expect) {
    save4print(s, k);
    assert_eq_ret(expect, Solution().maxVowels(s, k));
}

int main() {
    test("abciiidef", 3, 3);
    test("aeiou", 2, 2);
    test("leetcode", 3, 2);

    return 0;
}
