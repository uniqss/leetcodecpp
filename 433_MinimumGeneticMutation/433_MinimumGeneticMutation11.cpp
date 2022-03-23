#include "../inc.h"

/*
没有本质的区别，只是稍稍优化了一丢丢，少搜索一层
*/
class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        q.emplace(start);
        vector<char> vc = {'A', 'C', 'G', 'T'};
        std::unordered_set<string> dict;
        std::for_each(bank.begin(), bank.end(), [&](const std::string& str) { dict.insert(str); });
        if (dict.count(end) == 0) return -1;

        if (start == end) return 0;

        int depth = 0;
        while (!q.empty()) {
            auto qsize = q.size();
            ++depth;
            for (size_t i = 0; i < qsize; ++i) {
                string start = q.front();
                q.pop();
                string tmp = start;
                for (size_t i = 0; i < start.size(); ++i) {
                    for (char c : vc) {
                        if (start[i] == c) continue;
                        tmp[i] = c;
                        if (dict.count(tmp) > 0) {
                            if (tmp == end) return depth;
                            q.emplace(tmp);
                        }
                    }
                    tmp[i] = start[i];
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
    test("AACCGGTT", "AACCGGTA", {"AACCGGTA"}, 1);
    test("AACCGGTT", "AAACGGTA", {"AACCGGTA", "AACCGCTA", "AAACGGTA"}, 2);
    test("AAAAACCC", "AACCCCCC", {"AAAACCCC", "AAACCCCC", "AACCCCCC"}, 3);
    return 0;
}
