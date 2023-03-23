#include "../inc.h"

class SortedStack {
   public:
    SortedStack() {}

    void push(int val) {}

    void pop() {}

    int peek() {}

    bool isEmpty() {}
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    SortedStack* stk;
    vector<ComplexVal> ret;
    for (size_t i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "SortedStack") {
            stk = new SortedStack();
            ret.emplace_back(null);
        } else if (op == "push") {
            stk->push(param[0]);
            ret.emplace_back(null);
        } else if (op == "peek") {
            auto curr = stk->peek();
            ret.emplace_back(curr);
        } else if (op == "pop") {
            stk->pop();
            ret.emplace_back(null);
        } else if (op == "isEmpty") {
            auto curr = stk->isEmpty();
            ret.emplace_back(curr);
        }
    }
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(ops);
        print(params);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({"SortedStack", "pop", "pop", "push", "pop", "isEmpty"}, {{}, {}, {}, {1}, {}, {}},
         {null, null, null, null, null, true});
    test({"SortedStack", "push", "push", "peek", "pop", "peek"}, {{}, {1}, {2}, {}, {}, {}},
         {null, null, null, 1, null, 2});
    return 0;
}
