#include "../inc.h"

/*
图的搜索算法 还没过，硬闯此关
*/

struct PairHash {
    std::size_t operator()(const std::pair<int, int>& key) const {
        int64_t val = key.first;
        val <<= 32;
        val |= key.second;

        return std::hash<int64_t>()(val);
    }
};

void sortV2Inner(vector<vector<int>>& vvi) {
    std::for_each(vvi.begin(), vvi.end(), [](vector<int>& vi) { std::sort(vi.begin(), vi.end()); });
}

class Solution {
   public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ret;
        sortV2Inner(connections);
        std::unordered_set<pair<int, int>, PairHash> check_remain;
        for (auto it : connections) {
            check_remain.insert({it[0], it[1]});
        }
        std::unordered_set<pair<int, int>, PairHash> conns = check_remain;

        while (!check_remain.empty()) {
            auto curr = *check_remain.begin();
            int from = curr.first, to = curr.second;
            vector<vector<int>> another_way;
            haveAnotherWay(connections, from, to, another_way);
            if (!another_way.empty()) {
                sortV2Inner(another_way);
                for (auto it : another_way) {
                    check_remain.erase({it[0], it[1]});
                }
            }
        }

        for (auto it : check_remain) {
            ret.push_back({it.first, it.second});
        }

        return ret;
    }

    // 图的搜索算法，需要把from -> to 的直接路径过滤掉。。。。为什么我这么背，每次刷每日一题都是图。。。睡觉睡觉
    bool haveAnotherWay(unordered_set<pair<int, int>>& conns, int from, int to, vector<vector<int>>& another_way) {
        unordered_set<pair<int, int>, PairHash> excepts;
        excepts.insert({from, to});
        auto pair_from_to = make_pair(from, to);
        for (auto it : conns) {
            if (excepts.count(it) > 0) continue;
            if (it.first == from || it.second == from) {
            }
        }

        return false;
    }
};

void test(int n, vector<vector<int>>&& connections, vector<vector<int>>& expect) {
    Solution so;
    auto ret = so.criticalConnections(n, connections);
    sortvvrawInnerAndOuter(expect);
    sortvvrawInnerAndOuter(ret);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("not ok.");
        praw(n);
        pvvraw(connections);
        pvvraw(ret);
        pvvraw(expect);
        pnewline();
    }
}

int main() {
    return 0;
}
