#include "../inc.h"

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        stack<int> stk;
        for (int a : asteroids) {
            if (stk.empty() || stk.top() < 0 || a > 0) {
                stk.push(a);
            } else {  // a < 0
                while (!stk.empty() && stk.top() > 0 && stk.top() + a < 0) {
                    stk.pop();
                }

                if (stk.empty() || stk.top() < 0) {
                    stk.push(a);
                } else if (stk.top() + a == 0) {
                    stk.pop();
                }
            }
        }
        while (!stk.empty()) {
            ret.push_back(stk.top());
            stk.pop();
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

void test(vector<int>&& asteroids, const vector<int>& expect) {
    save4print(asteroids);
    assert_eq_ret(expect, Solution().asteroidCollision(asteroids));
}

int main() {
    test({5, 10, -5}, {5, 10});
    test({8, -8}, {});
    test({10, 2, -5}, {10});
    return 0;
}
