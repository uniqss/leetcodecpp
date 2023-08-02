#include "../inc.h"

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int a : asteroids) {
            while (a < 0 && !stk.empty() && stk.top() > 0 && stk.top() + a < 0) stk.pop();
            if (a < 0 && !stk.empty() && stk.top() + a == 0) {
                stk.pop();
            } else if (a < 0 && !stk.empty() && stk.top() + a > 0) {
            } else {
                stk.push(a);
            }
        }
        vector<int> ret;
        while (!stk.empty()) {
            ret.push_back(stk.top());
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
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
