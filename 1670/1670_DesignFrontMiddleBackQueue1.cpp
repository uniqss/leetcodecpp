#include "../inc.h"

class FrontMiddleBackQueue {
    deque<int> ql, qr;

   public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) { ql.emplace_front(val), adapt(); }

    void pushMiddle(int val) {
        if (ql.size() == qr.size())
            qr.emplace_front(val);
        else
            ql.emplace_back(val);
        adapt();
    }

    void pushBack(int val) { qr.emplace_back(val), adapt(); }

    int popFront() {
        if (qr.empty()) return -1;
        if (ql.empty()) {
            int ret = qr.front();
            qr.pop_front();
            return ret;
        } else {
            int ret = ql.front();
            ql.pop_front(), adapt();
            return ret;
        }
    }

    int popMiddle() {
        if (qr.empty()) return -1;
        if (ql.size() != qr.size()) {
            int ret = qr.front();
            qr.pop_front();
            return ret;
        } else {
            int ret = ql.back();
            ql.pop_back(), adapt();
            return ret;
        }
    }

    int popBack() {
        if (qr.empty()) return -1;
        int ret = qr.back();
        qr.pop_back(), adapt();
        return ret;
    }

   private:
    void adapt() {
        while (ql.size() > qr.size()) {
            qr.emplace_front(ql.back());
            ql.pop_back();
        }
        while (qr.size() > ql.size() + 1) {
            ql.emplace_back(qr.front());
            qr.pop_front();
        }
    }
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    vector<ComplexVal> ret;
    FrontMiddleBackQueue q;
    for (int i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "FrontMiddleBackQueue") {
            ret.emplace_back(null);
        } else if (op == "pushFront") {
            ret.emplace_back(null);
            q.pushFront(param[0]);
        } else if (op == "pushBack") {
            ret.emplace_back(null);
            q.pushBack(param[0]);
        } else if (op == "pushMiddle") {
            ret.emplace_back(null);
            q.pushMiddle(param[0]);
        } else if (op == "popFront") {
            auto curr = q.popFront();
            ret.emplace_back(curr);
        } else if (op == "popBack") {
            auto curr = q.popBack();
            ret.emplace_back(curr);
        } else if (op == "popMiddle") {
            auto curr = q.popMiddle();
            ret.emplace_back(curr);
        }
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle",
          "popMiddle", "popBack", "popFront"},
         {{}, {1}, {2}, {3}, {4}, {}, {}, {}, {}, {}}, {null, null, null, null, null, 1, 3, 4, 2, -1});
    return 0;
}
