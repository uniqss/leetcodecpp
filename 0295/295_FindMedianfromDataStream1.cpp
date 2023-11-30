#include "../inc.h"

class MedianFinder {
    priority_queue<int, vector<int>, std::greater<int>> large;
    priority_queue<int, vector<int>, std::less<int>> small;

   public:
    MedianFinder() {}

    void addNum(int num) {
        if (large.size() <= small.size()) {
            large.emplace(num);
        } else {
            small.emplace(num);
        }
        if (!large.empty() && !small.empty()) {
            while (large.top() < small.top()) {
                int l = large.top(), s = small.top();
                large.pop(), small.pop();
                large.emplace(s), small.emplace(l);
            }
        }
    }

    double findMedian() {
        if (large.size() == small.size()) return ((double)large.top() + (double)small.top()) / 2;
        return large.top();
    }
};

void test(vector<string>&& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    save4print(ops, params);
    MedianFinder mf;
    vector<ComplexVal> ret;
    for (int i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& paramsi = params[i];
        if (op == "MedianFinder") {
            ret.emplace_back(null);
        } else if (op == "addNum") {
            ret.emplace_back(null);
            mf.addNum(paramsi[0]);
        } else if (op == "findMedian") {
            auto curr = mf.findMedian();
            ret.emplace_back(curr);
        } else {
            assert_retnone(false);
        }
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"MedianFinder", "addNum", "findMedian", "addNum", "findMedian", "addNum", "findMedian", "addNum",
          "findMedian", "addNum", "findMedian"},
         {{}, {-1}, {}, {-2}, {}, {-3}, {}, {-4}, {}, {-5}, {}},
         {null, null, -1.00000, null, -1.50000, null, -2.00000, null, -2.50000, null, -3.00000});
    test({"MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"}, {{}, {1}, {2}, {}, {3}, {}},
         {null, null, null, 1.5, null, 2.0});
    return 0;
}
