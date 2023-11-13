#include "../inc.h"

class Solution {
    struct QElement {
        char c;
        int startidx = 0;
        int count = 0;
    };

   public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        deque<QElement> q;
        vector<int> scount(256), tcount(256);
        int qcount = 0, qvalidcount = 0, tsize = t.size(), mstart, mqcount, mwindow = INT_MAX;
        for (char c : t) ++tcount[c];
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (q.empty() || q.back().c != c) {
                q.push_back({c, i, 1});
            } else {
                ++q.back().count;
            }
            ++qcount;
            if (scount[c] < tcount[c]) ++qvalidcount;
            ++scount[c];
            while (!q.empty()) {
                auto curr = q.front();
                int wast = scount[curr.c] - tcount[curr.c];
                if (wast >= curr.count) {
                    qcount -= curr.count;
                    scount[curr.c] -= curr.count;
                    q.pop_front();
                } else if (wast > 0) {
                    qcount -= wast;
                    scount[curr.c] -= wast;
                    q.front().count -= wast;
                    q.front().startidx += wast;
                    break;
                } else {
                    break;
                }
            }
            if (qvalidcount >= tsize) {
                if (qcount < mwindow) {
                    mwindow = qcount;
                    mstart = q.front().startidx;
                    mqcount = qcount;
                }
            }
        }
        if (mwindow < INT_MAX) {
            return s.substr(mstart, mqcount);
        }
        return "";
    }
};

void test(string s, string t, const string& expect) {
    save4print(s, t);
    assert_eq_ret(expect, Solution().minWindow(s, t));
}

int main() {
    test("bba", "ab", "ba");
    test("ADOBECODEBANC", "ABC", "BANC");
    test("a", "a", "a");
    test("a", "aa", "");
    return 0;
}
