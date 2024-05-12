#include "../inc.h"

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0, r = (int)people.size() - 1, ret = 0;
        sort(people.begin(), people.end());
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                ++l, --r;
            } else {
                --r;
            }
            ++ret;
        }
        return ret;
    }
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
