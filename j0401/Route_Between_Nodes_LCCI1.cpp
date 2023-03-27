#include "../inc.h"

class Solution {
    struct GraphNode {
        int value;
        unordered_set<GraphNode*> nexts;
        GraphNode(int _value) : value(_value) {}
    };

   public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        unordered_map<int, GraphNode*> g;
        for (auto itgraph : graph) {
            int from = itgraph[0];
            int to = itgraph[1];
            auto itto = g.find(to);
            if (itto == g.end()) {
                GraphNode* nodeto = new GraphNode(to);
                g[to] = nodeto;
                itto = g.find(to);
            }
            auto itfrom = g.find(from);
            if (itfrom == g.end()) {
                GraphNode* nodefrom = new GraphNode(from);
                g[from] = nodefrom;
                itfrom = g.find(from);
            }
            itfrom->second->nexts.insert(itto->second);
        }

        auto itstart = g.find(start);
        if (itstart == g.end()) return false;
        auto ittarget = g.find(target);
        if (ittarget == g.end()) return false;
        queue<GraphNode*> q;
        q.emplace(itstart->second);
        unordered_set<GraphNode*> pushed;
        pushed.insert(itstart->second);
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (it == ittarget->second) return true;
            for (auto next : it->nexts) {
                if (pushed.count(next) == 0) {
                    q.push(next);
                    pushed.insert(next);
                }
            }
        }
        return false;
    }
};

void test(int n, vector<vector<int>>&& graph, int start, int target, bool expect) {
    Solution so;
    auto param = graph;
    auto ret = so.findWhetherExistsPath(n, graph, start, target);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(n);
        print(param);
        print(start);
        print(target);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test(25, {{0, 1}, {1, 12}}, 0, 12, true);
    test(3, {{0, 1}, {0, 2}, {1, 2}, {1, 2}}, 0, 2, true);
    test(5, {{0, 1}, {0, 2}, {0, 4}, {0, 4}, {0, 1}, {1, 3}, {1, 4}, {1, 3}, {2, 3}, {3, 4}}, 0, 4, true);
    test(25, {{0, 1},  {0, 3},   {0, 10},  {0, 18},  {1, 2},   {1, 7},   {1, 11},  {1, 12}, {2, 4},
              {2, 5},  {2, 13},  {2, 16},  {3, 6},   {3, 8},   {4, 9},   {5, 17},  {7, 20}, {7, 22},
              {8, 10}, {10, 19}, {11, 15}, {13, 14}, {14, 21}, {15, 23}, {19, 24}, {20, 22}},
         0, 12, true);

    return 0;
}
