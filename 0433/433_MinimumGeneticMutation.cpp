#include "../inc.h"

class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {}
};

void test(string&& start, string&& end, vector<string>&& bank, int expected) {
    save4print(start);
    save4print(end);
    save4print(bank);
    assert_eq_ret(expected, Solution().minMutation(start, end, bank));
}

int main() {
    test("AACCTTGG", "AATTCCGG", {"AATTCCGG", "AACCTGGG", "AACCCCGG", "AACCTACC"}, -1);
    test("AACCGGTT", "AACCGCAA", {"AACCGGTA", "AACCGGAA", "AACCGCAA"}, 3);
    test("AACCGGTT", "AACCGGTA", {}, -1);
    test("AACCGGTT", "AACCGGTA", {"AACCGGTA"}, 1);
    test("AACCGGTT", "AAACGGTA", {"AACCGGTA", "AACCGCTA", "AAACGGTA"}, 2);
    test("AAAAACCC", "AACCCCCC", {"AAAACCCC", "AAACCCCC", "AACCCCCC"}, 3);
    return 0;
}
