#include "../inc.h"

class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {}
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
