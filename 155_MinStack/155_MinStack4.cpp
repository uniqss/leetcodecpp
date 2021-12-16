#include "../stl.h"

// 或者也可以这样

class MinStack {
    // val, min
    stack<pair<int, int>> stackval;

   public:
    MinStack() {
    }

    void push(int val) {
        if (stackval.empty()) {
            stackval.push({val, val});
        } else {
            stackval.push({val, min(stackval.top().second, val)});
        }
    }

    void pop() {
        stackval.pop();
    }

    int top() {
        return stackval.top().first;
    }

    int getMin() {
        return stackval.top().second;
    }
};

MinStack* g_mstack = nullptr;

int test(const string& op, const vector<int>& args) {
    int ret = INT_MIN;
    if (op == "MinStack") {
        g_mstack = new MinStack();
    } else if (op == "push") {
        g_mstack->push(args[0]);
    } else if (op == "getMin") {
        ret = g_mstack->getMin();
    } else if (op == "pop") {
        g_mstack->pop();
    } else if (op == "top") {
        ret = g_mstack->top();
    }
    return ret;
}

int main() {
    vector<string> oplist;
    vector<vector<int>> argslist;
    vector<int> ret;

    oplist = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    argslist = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}};
    ret = {};
    for (size_t i = 0; i < oplist.size(); ++i) {
        const string& op = oplist[i];
        const vector<int>& arg = argslist[i];
        ret.push_back(test(op, arg));
    }
    pvi(ret);

    if (g_mstack != nullptr) {
        delete g_mstack;
        g_mstack = nullptr;
    }
    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

 */
