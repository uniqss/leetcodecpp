#include "../inc.h"

// 翻车1：想bfs秒，没秒掉，实质上是没看懂问题的本质
// 翻车2：貌似看懂了，但是只看了一层，通过了案例1，没通过案例2
// 翻车3：貌似又看懂了问题的本质，实则理解错误，车是一站一站跑，所以0-1，1-2，1-3时，只消耗3个油而不是4个，会在1拼车
// 问题的本质是一站一站把人搬到一起，除一下计算车的数量，取模额外派辆车
// 这里的图有个特征，只需把parent剔除就可以做到单向dfs而不需要用vis过滤判定已访问节点
class Solution {
    long long fuel = 0;
    int seats = 0;

   public:
    long long minimumFuelCost(vector<vector<int>>& roads, int s) {
        seats = s;
        int n = roads.size() + 1;
        long long ret = 0, rcount = 0;
        vector<vector<int>> tos(n);
        for (const auto& r : roads) tos[r[0]].emplace_back(r[1]), tos[r[1]].emplace_back(r[0]);
        dfs(tos, -1, 0, rcount);
        return fuel;
    }
    void dfs(const vector<vector<int>>& tos, int parent, int from, long long& rcount) {
        for (int to : tos[from]) {
            if (to == parent) continue;
            long long to_rcount = 1;
            dfs(tos, from, to, to_rcount);
            rcount += to_rcount;
            fuel += to_rcount / seats;
            if (to_rcount % seats != 0) ++fuel;
        }
    }
};

void test(vector<vector<int>>&& roads, int seats, long long expect) {
    save4print(roads, seats);
    assert_eq_ret(expect, Solution().minimumFuelCost(roads, seats));
}

int main() {
    test({{0, 1}, {0, 2}, {1, 3}, {1, 4}}, 5, 4);
    test({{0, 1}, {0, 2}, {0, 3}}, 5, 3);
    test({{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}}, 2, 7);
    return 0;
}
