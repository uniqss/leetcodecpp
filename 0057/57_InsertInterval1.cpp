#include "../inc.h"

/*
这题真特么烦，谁抽到去烧柱香吧，运气不好
*/
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), insertl = n, insertr = -1;
        for (int i = 0; i < n; ++i) {
            if (intervals[i][1] >= newInterval[0]) insertl = min(insertl, i);
            if (intervals[i][0] <= newInterval[1]) insertr = max(insertr, i);
        }
        if (insertl == n) {
            intervals.emplace_back(newInterval);
            return intervals;
        } else if (insertr == -1) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        } else if (insertl > insertr) {
            vector<vector<int>> ret;
            for (int i = 0; i < n; ++i) {
                ret.emplace_back(intervals[i]);
                if (i == insertr) {
                    ret.push_back(newInterval);
                }
            }
            return ret;
        } else {
            vector<vector<int>> ret;
            int l = min(newInterval[0], intervals[insertl][0]), r = max(newInterval[1], intervals[insertr][1]);
            for (int i = 0; i < n; ++i) {
                if (i < insertl || i > insertr) {
                    ret.emplace_back(intervals[i]);
                } else if (i == insertl) {
                    ret.push_back({l, r});
                }
            }
            return ret;
        }
    }
};

void test(vector<vector<int>>&& intervals, vector<int>&& newInterval, const vector<vector<int>>& expect) {
    save4print(intervals);
    save4print(newInterval);
    Solution so;
    auto ret = so.insert(intervals, newInterval);
    assert_eq_ret(expect, ret);
}

int main() {
    test({{3, 5}, {12, 15}}, {6, 6}, {{3, 5}, {6, 6}, {12, 15}});
    test({{1, 5}}, {0, 3}, {{0, 5}});
    test({{1, 3}, {6, 9}}, {2, 5}, {{1, 5}, {6, 9}});
    test({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}, {{1, 2}, {3, 10}, {12, 16}});
    return 0;
}
