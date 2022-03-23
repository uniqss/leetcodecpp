#include "../inc.h"

class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        q.emplace(start);
        vector<char> vc = {'A', 'C', 'G', 'T'};
        std::unordered_set<string> dict;
        std::for_each(bank.begin(), bank.end(), [&](const std::string& str) { dict.insert(str); });
        if (dict.count(end) == 0) return -1;

        int depth = 0;
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                string start = q.front();
                if (start == end) return depth;
                q.pop();
                string tmp = start;
                for (size_t i = 0; i < start.size(); ++i) {
                    for (char c : vc) {
                        if (start[i] == c) continue;
                        tmp[i] = c;
                        if (dict.count(tmp) > 0) {
                            q.emplace(tmp);
                        }
                    }
                    tmp[i] = start[i];
                }
            }
            // 这里事实上是树的高度要减掉1，因为我们不是在找到某节点的时候就判定的，是找到以后放进queue里面再多走了一层，理论上可以稍稍优化一点
            ++depth;
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
    test("AACCGGTT", "AACCGGTA", {"AACCGGTA"}, 1);
    test("AACCGGTT", "AAACGGTA", {"AACCGGTA", "AACCGCTA", "AAACGGTA"}, 2);
    test("AAAAACCC", "AACCCCCC", {"AAAACCCC", "AAACCCCC", "AACCCCCC"}, 3);
    return 0;
}
