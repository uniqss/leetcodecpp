#include "../inc.h"

class MinStack {
   public:
    MinStack() {}

    void push(int x) {}

    void pop() {}

    int top() {}

    int getMin() {}
};

void test(const vector<string>& ops, const vector<vector<int>>& params,
          const vector<ComplexVal>& expect) {
    save4print(ops, params);
    MinStack* pstack = nullptr;
    vector<ComplexVal> ret;
    for (size_t i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "MinStack") {
            pstack = new MinStack();
            ret.emplace_back(null);
        } else if (op == "push") {
            pstack->push(param[0]);
            ret.emplace_back(null);
        } else if (op == "pop") {
            pstack->pop();
            ret.emplace_back(null);
        } else if (op == "top") {
            auto val = pstack->top();
            ret.emplace_back(val);
        } else if (op == "getMin") {
            auto val = pstack->getMin();
            ret.emplace_back(val);
        }
    }
    assert_eq_ret(expect, ret);
    delete pstack;
}

int main() {
    test({"MinStack", "push", "push", "top", "getMin", "pop", "getMin", "top"},
         {{}, {1}, {2}, {}, {}, {}, {}, {}}, {null, null, null, 2, 1, null, 1, 1});
    test({"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"},
         {{}, {-2}, {0}, {-3}, {}, {}, {}, {}}, {null, null, null, null, -3, null, 0, -2});
    return 0;
}
