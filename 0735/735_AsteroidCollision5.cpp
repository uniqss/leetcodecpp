#include "../inc.h"

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> q;
        for (int a : asteroids) {
            while (a < 0 && !q.empty() && q.back() > 0 && q.back() + a < 0) {
                q.pop_back();
            }
            if (a < 0 && !q.empty() && q.back() + a == 0) {
                q.pop_back();
            } else if (a < 0 && !q.empty() && q.back() + a > 0) {
            } else {
                q.emplace_back(a);
            }
        }
        return {q.begin(), q.end()};
    }
};

void test(vector<int>&& asteroids, const vector<int>& expect) {
    save4print(asteroids);
    assert_eq_ret(expect, Solution().asteroidCollision(asteroids));
}

int main() {
    test({-2, -2, 1, -2}, {-2, -2, -2});
    test({5, 10, -5}, {5, 10});
    test({8, -8}, {});
    test({10, 2, -5}, {10});
    return 0;
}
