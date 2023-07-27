#include "../inc.h"

class Solution {
   public:
    int maxVowels(string s, int k) {
        int ret = 0, curr = 0, ssize = s.size();
        unordered_set<char> dict = {'a', 'e', 'i', 'o', 'u'};
        queue<int> q;
        for (int i = 0; i < k; ++i) {
            if (dict.count(s[i]) > 0) {
                ++curr;
                ret = max(ret, curr);
                if (!q.empty() && q.back() > 0)
                    ++q.back();
                else
                    q.push(1);
            } else {
                if (!q.empty() && q.back() < 0)
                    --q.back();
                else
                    q.push(-1);
            }
        }
        for (int i = k; i < ssize; ++i) {
            if (dict.count(s[i]) > 0) {
                ++curr;
                if (!q.empty() && q.back() > 0)
                    ++q.back();
                else
                    q.push(1);
            } else {
                if (!q.empty() && q.back() < 0)
                    --q.back();
                else
                    q.push(-1);
            }
            if (q.front() > 0) --curr;
            q.front() -= q.front() / abs(q.front());
            if (q.front() == 0) q.pop();
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
