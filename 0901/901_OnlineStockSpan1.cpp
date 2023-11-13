#include "../inc.h"

class StockSpanner {
    stack<pair<int, int>> stk;
    int idx = 0;

   public:
    StockSpanner() {
        ++idx;
        stk.emplace(idx, INT_MAX);
    }

    int next(int price) {
        ++idx;
        while (stk.top().second <= price) {
            stk.pop();
        }
        int ret = idx - stk.top().first;
        stk.emplace(idx, price);

        return ret;
    }
};

void test(vector<string>&& ops, vector<vector<int>>&& params, const vector<ComplexVal>& expect) {
    vector<ComplexVal> ret;
    StockSpanner ss;
    for (int i = 0; i < ops.size(); ++i) {
        auto op = ops[i];
        auto param = params[i];
        if (op == "StockSpanner") {
            ret.emplace_back(null);
        } else if (op == "next") {
            auto curr = ss.next(param[0]);
            ret.emplace_back(curr);
        }
    }
    assert_eq_ret(expect, ret);
    print(ops);
    print(params);
}

int main() {
    test({"StockSpanner", "next", "next", "next", "next", "next", "next", "next"},
         {{}, {100}, {80}, {60}, {70}, {60}, {75}, {85}}, {null, 1, 1, 1, 2, 1, 4, 6});
    return 0;
}