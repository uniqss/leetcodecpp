#include "../inc.h"

class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {}
};

void test(vector<string>&& deadends, string&& target, int expect) {
    save4print(deadends, target);
    assert_eq_ret(expect, Solution().openLock(deadends, target));
}

int main() {
    test({"0201", "0101", "0102", "1212", "2002"}, "0202", 6);
    test({"8888"}, "0009", 1);
    test({"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"}, "8888", -1);
    return 0;
}
