#include "../inc.h"

class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ret;
        int nsize = graph.size();
        /*
        先找到所有的 terminal nodes(no outgoing node)，记为 safe nodes
        再遍历 safe nodes，找所有指向 curr safe node 的节点 curr
            如果curr的所有outgoing都是 safe node 或者curr的outgoing为空
        最终在遍历中 safe nodes 的数量没变， safe nodes 就是需要返回的，组织一下数据即可
        */
        unordered_map<int, unordered_set<int>> tothis;
        vector<list<int>> outgoings(nsize);
        unordered_set<int> safe;
        for (int i = 0; i < nsize; ++i) {
            safe.insert(i);
        }

        for (int from = 0; from < nsize; ++from) {
            for (int to : graph[from]) {
                tothis[to].insert(from);
                safe.erase(from);
                outgoings[from].push_back(to);
            }
        }
        while (true) {
            bool changed = false;
            for (auto safenode : safe) {
                for (auto currtothis : tothis[safenode]) {
                    if (safe.count(currtothis) > 0) continue;
                    bool currsafe = true;
                    for (auto outgoing : outgoings[currtothis]) {
                        if (safe.count(outgoing) == 0) {
                            currsafe = false;
                            break;
                        }
                    }
                    if (currsafe) {
                        changed = true;
                        safe.insert(currtothis);
                    }
                }
            }
            if (!changed) break;
        }

        for (int i = 0; i < nsize; ++i) {
            if (safe.count(i) > 0) ret.emplace_back(i);
        }

        return ret;
    }
};

void test(vector<vector<int>>&& graph, vector<int>&& expect) {
    auto graph_param = graph;
    Solution so;
    auto ret = so.eventualSafeNodes(graph);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(graph_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}}, {2, 4, 5, 6});
    test({{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}}, {4});
    return 0;
}
