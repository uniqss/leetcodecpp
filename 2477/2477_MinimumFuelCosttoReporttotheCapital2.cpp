#include "../inc.h"

// 更苗条
class Solution {
   public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> conns(n + 1);
        for (const auto& r : roads) conns[r[1]].emplace_back(r[0]), conns[r[0]].emplace_back(r[1]);
        long long fuel = 0;
        function<int(int, int)> dfs = [&](int curr, int parent) -> int {
            int peoplesum = 1;
            for (auto next : conns[curr]) {
                if (next == parent) continue;
                int nextpeoplesum = dfs(next, curr);
                peoplesum += nextpeoplesum;
                fuel += (nextpeoplesum + seats - 1) / seats;
            }
            return peoplesum;
        };
        dfs(0, -1);
        return fuel;
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
