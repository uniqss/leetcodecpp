#include "../inc.h"

/*
考虑欠周，最开始是想直接跟层序遍历树一样，一层一层，每层除以k往上取整，加起来就好。
没考虑到的点：
1,2,3/4,5,6  4依赖12 5 依赖3 6依赖3 k=2
在第2个semaster的时候可以把4或者5干掉1科。因为只要第1个semaster选12，第2个semaster就能选3还能带上4
如何把这个cpuoffload的空缺补上？？？不能看着cpu睡大觉啊
这里补有没有讲究？如果只是判定下一layer里面依赖最少的，会不会有可以补2个的情况又需要额外判定是否可补2个比如：
1234/56789 k=3 5.123 6.234 7.124 8.234 9.134
那么就应该先234，再168，再579，让cpu offload的时候尽量满载，三个semaster干完全场
甚至有没有可能，补的时候，补到了第三layer？
k=3 1234567
*/
class Solution {
   public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        unordered_map<int, unordered_set<int>> deps;
        unordered_map<int, unordered_set<int>> nextcourses;
        unordered_set<int> nodeps;
        for (int i = 1; i <= n; ++i) nodeps.insert(i);
        for (auto relation : relations) {
            deps[relation[1]].insert(relation[0]);
            nextcourses[relation[0]].insert(relation[1]);
            nodeps.erase(relation[1]);
        }
        int ret = 0;
        int noDepTaken = 0, noDepCount = nodeps.size();
        while (!nodeps.empty()) {
            ret += std::ceil((float)nodeps.size() / k);
            for (int nodep : nodeps) {
                for (auto next : nextcourses[nodep]) {
                    deps[next].erase(nodep);
                }
            }
            unordered_set<int> newnodeps;
            for (int nodep : nodeps) {
                for (auto next : nextcourses[nodep]) {
                    if (deps[next].empty()) newnodeps.insert(next);
                }
            }

            nodeps.swap(newnodeps);
        }

        return ret;
    }
};

void test(int n, vector<vector<int>>&& relations, int k, int expect) {
    Solution so;
    auto relations_param = relations;
    auto ret = so.minNumberOfSemesters(n, relations, k);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(n);
        print(relations_param);
        print(k);
        print(expect);
        print(ret);
    }
}

int main() {
    test(13, {{12, 8}, {2, 4}, {3, 7},  {6, 8},  {11, 8}, {9, 4},  {9, 7}, {12, 4}, {11, 4},
              {6, 4},  {1, 4}, {10, 7}, {10, 4}, {1, 7},  {1, 8},  {2, 7}, {8, 4},  {10, 8},
              {12, 7}, {5, 4}, {3, 4},  {11, 7}, {7, 4},  {13, 4}, {9, 8}, {13, 8}},
         9, 3);
    test(4, {{2, 1}, {3, 1}, {1, 4}}, 2, 3);
    test(5, {{2, 1}, {3, 1}, {4, 1}, {1, 5}}, 2, 4);
    return 0;
}
