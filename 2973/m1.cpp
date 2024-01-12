#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()

class Solution {
    struct tnode {
        int idx;
        priority_queue<LL, vector<LL>, less<LL>> neg;
        priority_queue<LL, vector<LL>, greater<LL>> pos;
    };

   public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<LL> ret(n);
        vector<vector<int>> tos(n);
        for (const auto& e : edges) tos[e[1]].emplace_back(e[0]), tos[e[0]].emplace_back(e[1]);
        function<void(tnode&, int)> dfs = [&](tnode& curr, int from) {
            auto& neg = curr.neg;
            auto& pos = curr.pos;
            if (cost[curr.idx] >= 0) {
                pos.emplace(cost[curr.idx]);
                while (pos.size() > 3) pos.pop();
            } else {
                neg.emplace(cost[curr.idx]);
                while (neg.size() > 3) neg.pop();
            }
            for (int to : tos[curr.idx]) {
                if (from == to) continue;
                tnode tonode = {to};
                dfs(tonode, curr.idx);
                while (!tonode.neg.empty()) {
                    neg.emplace(tonode.neg.top()), tonode.neg.pop();
                    while (neg.size() > 3) neg.pop();
                }
                while (!tonode.pos.empty()) {
                    pos.emplace(tonode.pos.top()), tonode.pos.pop();
                    while (pos.size() > 3) pos.pop();
                }
            }
            if (pos.size() + neg.size() < 3) {
                ret[curr.idx] = 1;
            } else {
                vector<LL> posi, negi;
                if (pos.size() == 3) {
                    while (!pos.empty()) posi.emplace_back(pos.top()), pos.pop();
                    ret[curr.idx] = max(ret[curr.idx], posi[0] * posi[1] * posi[2]);
                    for (auto v : posi) pos.emplace(v);
                    posi.clear();
                }
                if (neg.size() >= 2 && pos.size() >= 1) {
                    while (!pos.empty()) posi.emplace_back(pos.top()), pos.pop();
                    while (!neg.empty()) negi.emplace_back(neg.top()), neg.pop();
                    ret[curr.idx] =
                        max(ret[curr.idx], posi[posi.size() - 1] * negi[negi.size() - 2] * negi[negi.size() - 1]);
                    for (auto v : posi) pos.emplace(v);
                    for (auto v : negi) neg.emplace(v);
                }
            }
        };
        tnode t0 = {0};
        dfs(t0, -1);

        return ret;
    }
};


void test(vector<vector<int>>&& edges, vector<int>&& cost, const vector<long long>& expect) {
    save4print(edges, cost);
    assert_eq_ret(expect, Solution().placedCoins(edges, cost));
}

int main() {
    test({{0, 8}, {8, 1}, {9, 2}, {4, 6}, {7, 4}, {3, 7}, {3, 8}, {5, 8}, {5, 9}},
         {-4, 83, -97, 40, 86, -85, -6, -84, -16, -53}, {709070, 1, 1, 43344, 1, 0, 1, 43344, 709070, 1});
    test({{0, 2}, {0, 6}, {1, 4}, {3, 5}, {7, 6}, {3, 6}, {1, 8}, {3, 1}, {9, 3}},
         {63, 13, -6, 20, 56, -14, 61, 25, -99, 54}, {215208, 0, 1, 77616, 1, 1, 184464, 1, 1, 1});
    test({{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}}, {1, 2, 3, 4, 5, 6}, {120, 1, 1, 1, 1, 1});
    test({{0, 1}, {0, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 6}, {2, 7}, {2, 8}}, {1, 4, 2, 3, 5, 7, 8, -4, 2},
         {280, 140, 32, 1, 1, 1, 1, 1, 1});
    test({{0, 1}, {0, 2}}, {1, 2, -2}, {0, 1, 1});
    return 0;
}
