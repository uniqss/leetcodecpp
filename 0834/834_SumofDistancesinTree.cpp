#include "../inc.h"

/*
思路：动态看，每加入的一个节点，一定只和一个节点连接
1   {}                                  {0}             {0}
2   {{0, 1}}                            {1, 1}          {1, 1}
3   {{0, 1}, {0, 2}}                    {2, 3, 3}       {1+1, 1+2, 1+2}
4   {{0, 1}, {0, 2}, {2, 3}}            {4, 6, 4, 6}    {2+2, 3+3, 3+1, 1+2+3}
5   {{0, 1}, {0, 2}, {2, 3}, {2, 4}}    {6, 9, 5, 8}    {4+2, 6+3, 4+1, 8}
*/

class Solution {
   public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ret(n);
        unordered_map<int, unordered_map<int, int>> dict;
        for (auto edge : edges) {
            dict[edge[0]][edge[1]] = 1;
            dict[edge[1]][edge[0]] = 1;
        }

        return ret;
    }
};

void test(int n, vector<vector<int>>&& edges, const vector<int>& expect) {
    auto edges_param = edges;
    Solution so;
    auto ret = so.sumOfDistancesInTree(n, edges);
    assert_eq_ret(expect, ret);
    print(n);
    print(edges);
}

int main() {
    test(6, {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}}, {8, 12, 6, 10, 10, 10});
    test(1, {}, {0});
    test(2, {{1, 0}}, {1, 1});
    return 0;
}
