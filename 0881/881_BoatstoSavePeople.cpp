#include "../inc.h"

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {}
};

void test(vector<int>&& people, int limit, int expect) {
    save4print(people, limit);
    assert_eq_ret(expect, Solution().numRescueBoats(people, limit));
}

int main() {
    test({1, 2}, 3, 1);
    test({3, 2, 2, 1}, 3, 3);
    test({3, 5, 3, 4}, 5, 4);
    return 0;
}
