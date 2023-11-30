#include "../inc.h"

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        deque<int> q;
        // 其实总共就4种情况
        for (int a : asteroids) {
            // 1.开撞，一路撞到底
            while (!q.empty() && a < 0 && q.back() > 0 && q.back() + a < 0) {
                q.pop_back();
            }
            // 2.与最后一个同归于尽
            if (!q.empty() && a < 0 && q.back() > 0 && q.back() + a == 0) {
                q.pop_back();
            } else if (!q.empty() && a < 0 && q.back() > 0 && q.back() + a > 0) {
                // 3.被最后一个吃掉
            } else {
                // 4.其他的所有情况统统的进队列
                q.push_back(a);
            }
        }
        ret.assign(q.begin(), q.end());

        return ret;
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
