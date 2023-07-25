#include "../inc.h"

class Solution {
   public:
    int maxVowels(string s, int k) {
        int curr = 0, ssize = s.size(), vmax = 0;
        unordered_set<char> dict = {'a', 'e', 'i', 'o', 'u'};
        deque<int> q;
        for (int i = 0; i < ssize; ++i) {
            if (i >= k) {
                if (q.front() > 0) {
                    --q.front();
                    --curr;
                }
                if (q.front() < 0) ++q.front();
                if (q.front() == 0) q.pop_front();
            }
            if (dict.count(s[i]) > 0) {
                if (q.empty() || q[q.size() - 1] < 0)
                    q.emplace_back(1);
                else
                    ++q[q.size() - 1];
                ++curr;
                vmax = std::max(vmax, curr);
            } else {
                if (q.empty() || q[q.size() - 1] > 0)
                    q.emplace_back(-1);
                else
                    --q[q.size() - 1];
            }
        }

        return vmax;
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
