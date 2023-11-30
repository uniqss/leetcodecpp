#include "../inc.h"

// 也行，丑一点
class MedianFinder {
    priority_queue<int, vector<int>, less<int>> qdown;
    priority_queue<int, vector<int>, greater<int>> qup;

   public:
    MedianFinder() {}
    void addNum(int num) {
        if (qdown.empty() || num >= qdown.top()) {
            qup.emplace(num);
            while (qup.size() > qdown.size() + 1) {
                qdown.emplace(qup.top());
                qup.pop();
            }
        } else {
            qdown.emplace(num);
            while (qup.size() < qdown.size()) {
                qup.emplace(qdown.top());
                qdown.pop();
            }
        }
    }
    double findMedian() {
        if (qup.size() == qdown.size()) return (qup.top() + qdown.top()) / 2.0;
        return qup.top();
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
