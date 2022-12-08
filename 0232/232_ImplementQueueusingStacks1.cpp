#include "../inc.h"

class MyQueue {
    stack<int> stk1;
    stack<int> stk2;

   public:
    MyQueue() {}

    void push(int x) { stk1.push(x); }

    int pop() {
        int ret = -1;
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        if (stk2.empty()) return -1;
        ret = stk2.top();
        stk2.pop();
        return ret;
    }

    int peek() {
        int ret = -1;
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        if (stk2.empty()) return -1;
        ret = stk2.top();
        return ret;
    }

    bool empty() { return stk1.empty() && stk2.empty(); }
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
