#include "../inc.h"

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {}
};

void test(vector<int>&& asteroids, const vector<int>& expect) {
    auto p1 = asteroids;
    Solution so;
    auto ret = so.asteroidCollision(asteroids);
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({-2, -2, 1, -2}, {-2, -2, -2});
    test({5, 10, -5}, {5, 10});
    test({8, -8}, {});
    test({10, 2, -5}, {10});
    return 0;
}
