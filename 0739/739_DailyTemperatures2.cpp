#include "../inc.h"

/*
这样的代码貌似更精纯
*/
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tsize = temperatures.size();
        stack<int> stk;
        vector<int> ret(tsize);
        for (int i = 0; i < tsize; ++i) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                int l = stk.top();
                stk.pop();
                ret[l] = i - l;
            }
            stk.emplace(i);
        }
        return ret;
    }
};

void test(vector<int>&& tempratures, vector<int>&& expect) {
    auto p1 = tempratures;
    Solution so;
    auto ret = so.dailyTemperatures(tempratures);
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0});
    test({30, 40, 50, 60}, {1, 1, 1, 0});
    test({30, 60, 90}, {1, 1, 0});
    return 0;
}
