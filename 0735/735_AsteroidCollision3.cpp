#include "../inc.h"

// 感觉这题应该用deque来解更容易理解
class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        deque<int> q;
        for (int a : asteroids) {
            if (q.empty() || a > 0 || q.back() < 0) {
                q.push_back(a);
            } else {
                // a < 0 && !q.empty() && q.back() > 0
                while (!q.empty() && q.back() > 0 && q.back() + a < 0) {
                    q.pop_back();
                }
                if (!q.empty() && q.back() + a == 0) {
                    q.pop_back();
                } else if (!q.empty() && q.back() + a > 0) {
                } else {
                    q.push_back(a);
                }
            }
        }
        while (!q.empty()) {
            ret.push_back(q.front());
            q.pop_front();
        }

        return ret;
    }
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
