#include "../inc.h"

/*
双向搜索，确实性能会高很多：
    .
   . .
  . . .
 . . . .
. . . . .
假设树是上图结构，基因突变了五次，单搜的话，我们的搜索访问节点数就是整个图的面积
    .
   . .
  . . .
   . .
    .
如果我们双向搜索，搜索的面积就是上图中的菱形。当突变次数比较大时，这个差值会非常巨大。树的每个节点的子节点数量越多，差越

*/
class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        std::unordered_set<string> dict(bank.begin(), bank.end());
        std::unordered_set<string> existed1 = {start};
        std::unordered_set<string> existed2 = {end};
        vector<char> vc = {'A', 'C', 'G', 'T'};
        queue<string> q1;
        queue<string> q2;
        if (dict.count(end) == 0) return -1;
        q1.emplace(start);
        q2.emplace(end);
        int depth = 0;
        string tmp;
        while (!q1.empty() && !q2.empty()) {
            ++depth;
            auto qsize1 = q1.size();
            auto qsize2 = q2.size();
            for (size_t idx = 0; idx < qsize1; ++idx) {
                start = q1.front();
                q1.pop();
                tmp = start;
                for (size_t i = 0; i < tmp.size(); ++i) {
                    for (char c : vc) {
                        if (tmp[i] == c) continue;
                        tmp[i] = c;
                        if (dict.count(tmp) == 0) continue;
                        if (existed1.count(tmp) > 0) continue;
                        existed1.insert(tmp);
                        if (existed2.count(tmp) > 0) return depth + depth - 1;
                        q1.emplace(tmp);
                    }
                    tmp[i] = start[i];
                }
            }
            for (size_t idx = 0; idx < qsize2; ++idx) {
                end = q2.front();
                q2.pop();
                tmp = end;
                for (size_t i = 0; i < tmp.size(); ++i) {
                    for (char c : vc) {
                        if (tmp[i] == c) continue;
                        tmp[i] = c;
                        if (dict.count(tmp) == 0) continue;
                        if (existed2.count(tmp) > 0) continue;
                        existed2.insert(tmp);
                        if (existed1.count(tmp) > 0) return depth + depth;
                        q2.emplace(tmp);
                    }
                    tmp[i] = end[i];
                }
            }
        }
        return -1;
    }
};

void test(string&& start, string&& end, vector<string>&& bank, int expected) {
    Solution so;
    auto ret = so.minMutation(start, end, bank);
    if (ret == expected) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(start);
        praw(end);
        pvraw(bank);
        praw(expected);
        praw(ret);
        pnewline();
    }
}

int main() {
    test("AACCGGTT", "AACCGCAA", {"AACCGGTA", "AACCGGAA", "AACCGCAA"}, 3);
    test("AACCGGTT", "AACCGGTA", {}, -1);
    test("AACCGGTT", "AACCGGTA", {"AACCGGTA"}, 1);
    test("AACCGGTT", "AAACGGTA", {"AACCGGTA", "AACCGCTA", "AAACGGTA"}, 2);
    test("AAAAACCC", "AACCCCCC", {"AAAACCCC", "AAACCCCC", "AACCCCCC"}, 3);
    return 0;
}
