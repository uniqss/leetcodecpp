#include "../inc.h"

class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        std::unordered_set<string> dict(bank.begin(), bank.end());
        std::unordered_set<string> existed;
        vector<char> vc = {'A', 'C', 'G', 'T'};
        queue<string> q;
        q.emplace(start);
        int depth = 0;
        while (!q.empty()) {
            ++depth;
            auto qsize = q.size();
            for (size_t idx = 0; idx < qsize; ++idx) {
                start = q.front();
                q.pop();
                string tmp = start;
                for (size_t i = 0; i < tmp.size(); ++i) {
                    for (char c : vc) {
                        if (tmp[i] == c) continue;
                        tmp[i] = c;
                        if (dict.count(tmp) == 0) continue;
                        if (existed.count(tmp) > 0) continue;
                        existed.insert(tmp);
                        if (tmp == end) return depth;
                        q.emplace(tmp);
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
        print("ok.");
    } else {
        print("not ok.");
        print(start);
        print(end);
        print(bank);
        print(expected);
        print(ret);
        print();
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
