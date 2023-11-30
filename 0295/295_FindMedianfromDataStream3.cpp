#include "../inc.h"

// 鸳鸯戏水
class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> qlarge;
    priority_queue<int, vector<int>, less<int>> qsmall;

   public:
    MedianFinder() {}
    void addNum(int num) {
        if (qlarge.size() == qsmall.size())
            qlarge.emplace(num);
        else
            qsmall.emplace(num);
        if (!qsmall.empty()) {
            while (qlarge.top() < qsmall.top()) {
                qlarge.emplace(qsmall.top()), qsmall.pop();
                qsmall.emplace(qlarge.top()), qlarge.pop();
            }
        }
    }
    double findMedian() {
        if (qlarge.size() > qsmall.size()) return qlarge.top();
        return (qlarge.top() + qsmall.top()) / 2.0;
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
