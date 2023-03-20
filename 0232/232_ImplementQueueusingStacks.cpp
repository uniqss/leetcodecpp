#include "../inc/inc.h"

class MyQueue {
   public:
    MyQueue() {}

    void push(int x) {}

    int pop() {}

    int peek() {}

    bool empty() {}
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    MyQueue q;
    vector<ComplexVal> rets;
    for (size_t i = 0; i < ops.size(); ++i) {
        const string& op = ops[i];
        const vector<int>& param = params[i];
        ComplexVal ret = null;
        if (op == "MyQueue") {
        } else if (op == "push") {
            q.push(param[0]);
        } else if (op == "peek") {
            ret = q.peek();
        } else if (op == "pop") {
            ret = q.pop();
        } else if (op == "empty") {
            ret = q.empty();
        }

        rets.emplace_back(ret);
    }
    if (rets == expect) {
        print("ok");
    } else {
        print("not ok");
        print(ops);
        print(params);
        print(expect);
        print(rets);
        print();
    }
}

int main() {
    test({"MyQueue", "push", "push", "peek", "pop", "empty"}, {{}, {1}, {2}, {}, {}, {}}, {null, null, null, 1, 1, false});
    return 0;
}
