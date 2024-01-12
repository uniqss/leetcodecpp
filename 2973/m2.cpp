#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()

class Solution {
    struct tnode {
        int idx;
        priority_queue<int, vector<int>, greater<int>> qpos, qneg;
    };

   public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<long long> ans(n);
        vector<vector<int>> tos(n);
        for (const auto& e : edges) tos[e[1]].emplace_back(e[0]), tos[e[0]].emplace_back(e[1]);
        function<void(tnode&, int)> dfs = [&](tnode& curr, int parent) {
            if (cost[curr.idx] >= 0) {
                curr.qpos.emplace(cost[curr.idx]);
            } else {
                curr.qneg.emplace(-cost[curr.idx]);
            }
            for (int to : tos[curr.idx]) {
                if (to == parent) continue;
                tnode nto;
                nto.idx = to;
                dfs(nto, curr.idx);
                while (!nto.qpos.empty()) curr.qpos.emplace(nto.qpos.top()), nto.qpos.pop();
                while (!nto.qneg.empty()) curr.qneg.emplace(nto.qneg.top()), nto.qneg.pop();
            }
            while (curr.qpos.size() > 3) curr.qpos.pop();
            while (curr.qneg.size() > 3) curr.qneg.pop();
            vector<LL> tmppos, tmpneg;
            while (!curr.qpos.empty()) tmppos.emplace_back(curr.qpos.top()), curr.qpos.pop();
            while (!curr.qneg.empty()) tmpneg.emplace_back(curr.qneg.top()), curr.qneg.pop();
            reverse(ALL(tmppos)), reverse(ALL(tmpneg));
            if (tmppos.size() + tmpneg.size() < 3) ans[curr.idx] = 1;
            if (tmppos.size() >= 3)
                ans[curr.idx] = max(ans[curr.idx], tmppos[0] * tmppos[1] * tmppos[2]);
            if (tmppos.size() >= 1 && tmpneg.size() >= 2)
                ans[curr.idx] = max(ans[curr.idx], tmppos[0] * tmpneg[0] * tmpneg[1]);
            if (tmpneg.size() == 1 && tmppos.size() == 2) ans[curr.idx] = 0;
            for (LL tmp : tmppos) curr.qpos.emplace(tmp);
            for (LL tmp : tmpneg) curr.qneg.emplace(tmp);
        };
        tnode t0;
        t0.idx = 0;
        dfs(t0, -1);
        return ans;
    }
};


void test(vector<vector<int>>&& edges, vector<int>&& cost, const vector<long long>& expect) {
    save4print(edges, cost);
    assert_eq_ret(expect, Solution().placedCoins(edges, cost));
}

int main() {
    test({{0, 8}, {8, 1}, {9, 2}, {4, 6}, {7, 4}, {3, 7}, {3, 8}, {5, 8}, {5, 9}},
         {-4, 83, -97, 40, 86, -85, -6, -84, -16, -53},
         {709070, 1, 1, 43344, 1, 0, 1, 43344, 709070, 1});
    test({{0, 2}, {0, 6}, {1, 4}, {3, 5}, {7, 6}, {3, 6}, {1, 8}, {3, 1}, {9, 3}},
         {63, 13, -6, 20, 56, -14, 61, 25, -99, 54}, {215208, 0, 1, 77616, 1, 1, 184464, 1, 1, 1});
    test({{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}}, {1, 2, 3, 4, 5, 6}, {120, 1, 1, 1, 1, 1});
    test({{0, 1}, {0, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 6}, {2, 7}, {2, 8}},
         {1, 4, 2, 3, 5, 7, 8, -4, 2}, {280, 140, 32, 1, 1, 1, 1, 1, 1});
    test({{0, 1}, {0, 2}}, {1, 2, -2}, {0, 1, 1});
    return 0;
}
