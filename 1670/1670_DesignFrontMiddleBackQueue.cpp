#include "../inc.h"

class FrontMiddleBackQueue {
   public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {}

    void pushMiddle(int val) {}

    void pushBack(int val) {}

    int popFront() {}

    int popMiddle() {}

    int popBack() {}
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    save4print(ops, params);
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
