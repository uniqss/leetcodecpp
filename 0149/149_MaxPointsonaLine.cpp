#include "../inc.h"

class Solution {
    pair<int, int> normanize(int a, int b) {
        if (b < 0) a *= -1, b *= -1;
        if (a == 0) return {0, 0};
        if (b == 1) return {a, 1};
        if ((a % b) == 0) a /= b;
        int newa = a, newb = b;
        for (int i = 1; i <= newa && i <= newb; ++i) {
            if (newa % i == 0 && newb % i == 0) {
                newa /= i, newb /= i;
            }
        }
        return {newa, newb};
    }

   public:
    int maxPoints(vector<vector<int>>& points) {
        int count = 0, psize = points.size();
        if (psize <= 2) return psize;
        unordered_map<string, int> dict;
        unordered_map<int, int> samex2count;
        for (int i = 1; i < psize; ++i) {
            for (int j = 0; j < i; ++j) {
                int x0 = points[i][0], y0 = points[i][1];
                int x1 = points[j][0], y1 = points[j][1];
                // y0 = ax0 + b
                // y1 = ax1 + b
                // a = (y1 - y0) / (x1 - x0)
                // b = y0 - a * x0
                if (x0 == x1) {
                    count = max(count, ++samex2count[x0]);
                    continue;
                }
                auto na = normanize(y1 - y0, x1 - x0);
                auto nb = normanize((x1 - x0) * y0 + (y1 - y0) * x0, x1 - x0);
                string k = to_string(na.first) + "/" + to_string(na.second) + "|" + to_string(nb.first) + "/" +
                           to_string(nb.second);
                count = max(count, ++dict[k]);
            }
        }
        // (n * (n - 1)) / 2 = count 求n
        // n^2 - n = 2 * count
        count *= 2;
        int l = 1, r = count, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            int vmid = mid * (mid - 1);
            if (vmid == count) {
                return mid;
            }
            if (vmid > count) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

void test(vector<vector<int>>&& points, int expect) {
    save4print(points);
    assert_eq_ret(expect, Solution().maxPoints(points));
}

int main() {
    test({{54, 153},   {1, 3},   {0, -72},    {-3, 3},     {12, -22}, {-60, -322}, {0, -5},     {-5, 1},
          {5, 5},      {36, 78}, {3, -4},     {5, 0},      {0, 4},    {-30, -197}, {-5, 0},     {60, 178},
          {0, 0},      {30, 53}, {24, 28},    {4, 5},      {2, -2},   {-18, -147}, {-24, -172}, {-36, -222},
          {-42, -247}, {2, 3},   {-12, -122}, {-54, -297}, {6, -47},  {-5, 3},     {-48, -272}, {-4, -2},
          {3, -2},     {0, 2},   {48, 128},   {4, 3},      {2, 4}},
         18);
    test({{2, 3}, {3, 3}, {-5, 3}}, 3);
    test({{0, 0}}, 1);
    test({{0, 0}, {4, 5}, {7, 8}, {8, 9}, {5, 6}, {3, 4}, {1, 1}}, 5);
    test({{4, 5}, {4, -1}, {4, 0}}, 3);
    test({{1, 1}, {2, 2}, {3, 3}}, 3);
    test({{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}, 4);
    return 0;
}
