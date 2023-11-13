#include "../inc.h"

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tsize = temperatures.size();
        vector<int> ret(tsize);
        deque<pair<int, int>> q;
        for (int i = 0; i < temperatures.size(); ++i) {
            auto t = temperatures[i];
            while (!q.empty() && q.back().second < t) {
                auto pidx = q.back().first;
                ret[pidx] = i - pidx;
                q.pop_back();
            }

            q.emplace_back(i, t);
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
